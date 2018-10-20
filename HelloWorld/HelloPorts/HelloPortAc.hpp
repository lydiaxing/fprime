/*
 * HelloPort.hpp
 *
 *  Created on: Thursday, 18 October 2018
 *  Author:     eryn
 *
 */
#ifndef HELLOPORT_HPP_
#define HELLOPORT_HPP_

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

    /// Input Hello port description
    /// 

    class InputHelloPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(I32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, I32 hello); //!< port callback definition

        InputHelloPort(void); //!< constructor
        void init(void); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(I32 hello); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        void invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Input Hello port description
    /// 
    
    class OutputHelloPort : public Fw::OutputPortBase {
      public: 
        OutputHelloPort(void);
        void init(void);
        void addCallPort(InputHelloPort* callPort);
        void invoke(I32 hello);
      protected:
      private:
        InputHelloPort* m_port;
    };
} // end namespace HelloWorld
#endif /* HELLO_HPP_ */

