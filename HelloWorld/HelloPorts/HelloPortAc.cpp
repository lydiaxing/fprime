#include <Fw/Cfg/Config.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>

#include <HelloWorld/HelloPorts/HelloPortAc.hpp>
namespace HelloWorld {


    namespace {

        class HelloPortBuffer : public Fw::SerializeBufferBase {

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

            U8 m_buff[InputHelloPort::SERIALIZED_SIZE];

        };

    }
    InputHelloPort::InputHelloPort(void) : 
        Fw::InputPortBase(), 
        m_func(0) {
    }
    
    void InputHelloPort::init(void) {
        Fw::InputPortBase::init();
    }

    void InputHelloPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputHelloPort::invoke(I32 hello) {

#if FW_PORT_TRACING == 1        
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, hello);
    }

#if FW_PORT_SERIALIZATION == 1    
    void InputHelloPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        I32 hello;
        _status = buffer.deserialize(hello);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        this->m_func(this->m_comp, this->m_portNum, hello);
    }
#endif

OutputHelloPort::OutputHelloPort(void) :
            Fw::OutputPortBase(),
    m_port(0) {
}

void OutputHelloPort::init(void) {
    Fw::OutputPortBase::init();
}

void OutputHelloPort::addCallPort(InputHelloPort* callPort) {
    FW_ASSERT(callPort);
    
    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = 0;
#endif
}

void OutputHelloPort::invoke(I32 hello) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION            
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(hello);
#if FW_PORT_SERIALIZATION            
    } else if (this->m_serPort) {
        Fw::SerializeStatus status;
        HelloPortBuffer _buffer;
        status = _buffer.serialize(hello);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        this->m_serPort->invokeSerial(_buffer);
    }
#else
    }    
#endif

} // end OutputHelloPort::invoke(...)

} // end namespace HelloWorld
