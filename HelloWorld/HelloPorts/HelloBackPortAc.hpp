/*
 * HelloBackPort.hpp
 *
 *  Created on: Friday, 12 October 2018
 *  Author:     eryn
 *
 */
#ifndef HELLOBACKPORT_HPP_
#define HELLOBACKPORT_HPP_

#include <cstring>
#include <cstdio>
#include <Fw/Cfg/Config.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace HelloWorld {

    /// Input HelloBack port description
    /// 

    class InputHelloBackPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(I32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, I32 helloback); //!< port callback definition

        InputHelloBackPort(void); //!< constructor
        void init(void); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(I32 helloback); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        void invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Input HelloBack port description
    /// 
    
    class OutputHelloBackPort : public Fw::OutputPortBase {
      public: 
        OutputHelloBackPort(void);
        void init(void);
        void addCallPort(InputHelloBackPort* callPort);
        void invoke(I32 helloback);
      protected:
      private:
        InputHelloBackPort* m_port;
    };
} // end namespace HelloWorld
#endif /* HELLOBACK_HPP_ */

