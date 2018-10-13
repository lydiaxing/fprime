#include <Fw/Cfg/Config.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>

#include <HelloWorld/HelloPorts/HelloBackPortAc.hpp>
namespace HelloWorld {


    namespace {

        class HelloBackPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity(void) const {
                    return sizeof(m_buff);
                }

                U8* getBuffAddr(void) {
                    return m_buff;
                }

                const U8* getBuffAddr(void) const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputHelloBackPort::SERIALIZED_SIZE];

        };

    }
    InputHelloBackPort::InputHelloBackPort(void) : 
        Fw::InputPortBase(), 
        m_func(0) {
    }
    
    void InputHelloBackPort::init(void) {
        Fw::InputPortBase::init();
    }

    void InputHelloBackPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputHelloBackPort::invoke(I32 helloback) {

#if FW_PORT_TRACING == 1        
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, helloback);
    }

#if FW_PORT_SERIALIZATION == 1    
    void InputHelloBackPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        I32 helloback;
        _status = buffer.deserialize(helloback);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        this->m_func(this->m_comp, this->m_portNum, helloback);
    }
#endif

OutputHelloBackPort::OutputHelloBackPort(void) :
            Fw::OutputPortBase(),
    m_port(0) {
}

void OutputHelloBackPort::init(void) {
    Fw::OutputPortBase::init();
}

void OutputHelloBackPort::addCallPort(InputHelloBackPort* callPort) {
    FW_ASSERT(callPort);
    
    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = 0;
#endif
}

void OutputHelloBackPort::invoke(I32 helloback) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION            
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(helloback);
#if FW_PORT_SERIALIZATION            
    } else if (this->m_serPort) {
        Fw::SerializeStatus status;
        HelloBackPortBuffer _buffer;
        status = _buffer.serialize(helloback);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        this->m_serPort->invokeSerial(_buffer);
    }
#else
    }    
#endif

} // end OutputHelloBackPort::invoke(...)

} // end namespace HelloWorld
