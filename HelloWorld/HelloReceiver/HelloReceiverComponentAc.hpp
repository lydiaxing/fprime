// ====================================================================== 
// \title  HelloReceiverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for HelloReceiver component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
// 
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ====================================================================== 

#ifndef HELLORECEIVER_COMP_HPP_
#define HELLORECEIVER_COMP_HPP_

#include <Fw/Cfg/Config.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <HelloWorld/HelloPorts/HelloPortAc.hpp>
#include <HelloWorld/HelloPorts/HelloBackPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <HelloWorld/HelloTypes/HelloSerializableAc.hpp>

namespace HelloWorld {

  //! \class HelloReceiverComponentBase
  //! \brief Auto-generated base for HelloReceiver component
  //!
  class HelloReceiverComponentBase :
    public Fw::QueuedComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class HelloReceiverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return HelloIn[portNum]
    //!
    HelloWorld::InputHelloPort* get_HelloIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return SchedIn[portNum]
    //!
    Svc::InputSchedPort* get_SchedIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return CmdDisp[portNum]
    //!
    Fw::InputCmdPort* get_CmdDisp_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to HelloOut[portNum]
    //!
    void set_HelloOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        HelloWorld::InputHelloBackPort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdResponsePort *port /*!< The port*/
    );

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdRegPort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to HelloOut[portNum]
    //!
    void set_HelloOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

#endif

  public:

    // ----------------------------------------------------------------------
    // Command registration
    // ----------------------------------------------------------------------

    //! \brief Register commands with the Command Dispatcher
    //!
    //! Connect the dispatcher first
    //!
    void regCommands(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

#if FW_OBJECT_NAMES == 1
    //! Construct a HelloReceiverComponentBase object
    //!
    HelloReceiverComponentBase(
        const char* compName /*!< Component name*/
    );
#else
    //! Construct a HelloReceiverComponentBase object
    //!
    HelloReceiverComponentBase(void);
#endif

    //! Initialize a HelloReceiverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a HelloReceiverComponentBase object
    //!
    virtual ~HelloReceiverComponentBase(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port HelloIn
    //
    virtual void HelloIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        I32 hello 
    ) = 0;

    //! Handler for input port SchedIn
    //
    virtual void SchedIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port HelloIn
    //!
    void HelloIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        I32 hello 
    );

    //! Handler base-class function for input port SchedIn
    //!
    void SchedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for typed async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port HelloIn
    //!
    virtual void HelloIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        I32 hello 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port HelloOut
    //!
    void HelloOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        I32 helloback 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of HelloIn input ports
    //!
    //! \return The number of HelloIn input ports
    //!
    NATIVE_INT_TYPE getNum_HelloIn_InputPorts(void);

    //! Get the number of SchedIn input ports
    //!
    //! \return The number of SchedIn input ports
    //!
    NATIVE_INT_TYPE getNum_SchedIn_InputPorts(void);

    //! Get the number of CmdDisp input ports
    //!
    //! \return The number of CmdDisp input ports
    //!
    NATIVE_INT_TYPE getNum_CmdDisp_InputPorts(void);

  
    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------
    
    enum {
       NUM_HELLOIN_INPUT_PORTS = 1,
       NUM_SCHEDIN_INPUT_PORTS = 1,
       NUM_CMDDISP_INPUT_PORTS = 1,
    };
  
  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of HelloOut output ports
    //!
    //! \return The number of HelloOut output ports
    //!
    NATIVE_INT_TYPE getNum_HelloOut_OutputPorts(void);

    //! Get the number of CmdStatus output ports
    //!
    //! \return The number of CmdStatus output ports
    //!
    NATIVE_INT_TYPE getNum_CmdStatus_OutputPorts(void);

    //! Get the number of CmdReg output ports
    //!
    //! \return The number of CmdReg output ports
    //!
    NATIVE_INT_TYPE getNum_CmdReg_OutputPorts(void);

    //! Get the number of Tlm output ports
    //!
    //! \return The number of Tlm output ports
    //!
    NATIVE_INT_TYPE getNum_Tlm_OutputPorts(void);

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts(void);

    //! Get the number of Log output ports
    //!
    //! \return The number of Log output ports
    //!
    NATIVE_INT_TYPE getNum_Log_OutputPorts(void);

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts(void);
#endif

  
    enum {
       NUM_HELLOOUT_OUTPUT_PORTS = 1,
       NUM_CMDSTATUS_OUTPUT_PORTS = 1,
       NUM_CMDREG_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
    };
  
  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port HelloOut is connected
    //!
    //! \return Whether port HelloOut is connected
    //!
    bool isConnected_HelloOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port CmdStatus is connected
    //!
    //! \return Whether port CmdStatus is connected
    //!
    bool isConnected_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port CmdReg is connected
    //!
    //! \return Whether port CmdReg is connected
    //!
    bool isConnected_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Tlm is connected
    //!
    //! \return Whether port Tlm is connected
    //!
    bool isConnected_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Log is connected
    //!
    //! \return Whether port Log is connected
    //!
    bool isConnected_Log_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Message dispatch
    // ----------------------------------------------------------------------

    //! Dispatch a message on the queue
    //!
    virtual MsgDispatchStatus doDispatch(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_SET_RESPONSE = 0, /* Response : 1 for hello; 2 for helloback */
      OPCODE_CLEAR_EVENT_THROTTLE = 1, /* Clear the event throttle */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command SET_RESPONSE
    /* Response : 1 for hello; 2 for helloback */
    virtual void SET_RESPONSE_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

    //! Handler for command CLEAR_EVENT_THROTTLE
    /* Clear the event throttle */
    virtual void CLEAR_EVENT_THROTTLE_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for async commands.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing the
    // corresponding command. By default they do nothing. You can
    // override them to provide specific pre-command behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for command SET_RESPONSE
    //!
    virtual void SET_RESPONSE_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CLEAR_EVENT_THROTTLE
    //!
    virtual void CLEAR_EVENT_THROTTLE_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command SET_RESPONSE
    //! 
    void SET_RESPONSE_cmdHandlerBase( 
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CLEAR_EVENT_THROTTLE
    //! 
    void CLEAR_EVENT_THROTTLE_cmdHandlerBase( 
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command response
    // ----------------------------------------------------------------------

    //! Emit command response
    //!
    void cmdResponse_out(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CommandResponse response /*!< The command response*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_HELLO_REPLIED = 0, /* Hello replied */
      EVENTID_THROTTLE_CLEARED = 1, /* Event throttle cleared */
    };
    
    // ----------------------------------------------------------------------
    // Event Throttle values - sets initial value of countdown variable
    // ----------------------------------------------------------------------

    enum {
      EVENTID_HELLO_REPLIED_THROTTLE = 3, /*!< Throttle reset count for HELLO_REPLIED*/
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event HELLO_REPLIED
    //!
    /* Hello replied */
    void log_ACTIVITY_HI_HELLO_REPLIED(
        I32 helloback /*!< The reply = 2*/
    );
    
    // reset throttle value for HELLO_REPLIED
    void log_ACTIVITY_HI_HELLO_REPLIED_ThrottleClear(void);

    //! Log event THROTTLE_CLEARED
    //!
    /* Event throttle cleared */
    void log_ACTIVITY_HI_THROTTLE_CLEARED(
        void
    );
    

  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_NUM_HELLOS = 0, //!< Channel ID for NUM_HELLOS
      CHANNELID_GREET = 1, //!< Channel ID for GREET
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel NUM_HELLOS
    //!
    /* The number of hellos */
    void tlmWrite_NUM_HELLOS(
        U32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel GREET
    //!
    /* Record exchanges of hello/helloback */
    void tlmWrite_GREET(
        HelloWorld::Hello& arg /*!< The telemetry value*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //! Get the time
    //!
    //! \return The current time
    //!
    Fw::Time getTime(void);


  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port HelloIn
    //!
    HelloWorld::InputHelloPort m_HelloIn_InputPort[NUM_HELLOIN_INPUT_PORTS];

    //! Input port SchedIn
    //!
    Svc::InputSchedPort m_SchedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

    //! Input port CmdDisp
    //!
    Fw::InputCmdPort m_CmdDisp_InputPort[NUM_CMDDISP_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port HelloOut
    //!
    HelloWorld::OutputHelloBackPort m_HelloOut_OutputPort[NUM_HELLOOUT_OUTPUT_PORTS];

    //! Output port CmdStatus
    //!
    Fw::OutputCmdResponsePort m_CmdStatus_OutputPort[NUM_CMDSTATUS_OUTPUT_PORTS];

    //! Output port CmdReg
    //!
    Fw::OutputCmdRegPort m_CmdReg_OutputPort[NUM_CMDREG_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port HelloIn
    //!
    static void m_p_HelloIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        I32 hello 
    );

    //! Callback for port SchedIn
    //!
    static void m_p_SchedIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    );

    //! Callback for port CmdDisp
    //!
    static void m_p_CmdDisp_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< Command Op Code*/
        U32 cmdSeq, /*!< Command Sequence*/
        Fw::CmdArgBuffer &args /*!< Buffer containing arguments*/
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------
    NATIVE_UINT_TYPE m_HELLO_REPLIEDThrottle; //!< throttle for HELLO_REPLIED

  };  

} // end namespace HelloWorld
#endif
