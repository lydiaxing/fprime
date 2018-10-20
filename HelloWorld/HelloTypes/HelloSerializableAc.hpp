/*
 * Hello.hpp
 *
 *  Created on: Saturday, 20 October 2018
 *  Author:     science
 *
 */
#ifndef HELLO_HPP_
#define HELLO_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/StringType.hpp>
#include <stdio.h> // snprintf
#ifdef BUILD_UT
#include <iostream>
#include <Fw/Types/EightyCharString.hpp>
#endif
#endif

namespace HelloWorld {

class Hello : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(I32) +
        sizeof(I32)
    }; //!< serializable size of Hello

    Hello(void); //!< Default constructor
    Hello(const Hello* src); //!< pointer copy constructor
    Hello(const Hello& src); //!< reference copy constructor
    Hello(I32 hello, I32 helloback); //!< constructor with arguments
    const Hello& operator=(const Hello& src); //!< equal operator
    bool operator==(const Hello& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const Hello& obj);
#endif

    void set(I32 hello, I32 helloback); //!< set values
    
    I32 gethello(void); //!< get member hello
    I32 gethelloback(void); //!< get member helloback

    void sethello(I32 val); //!< set member hello
    void sethelloback(I32 val); //!< set member helloback


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x60052A89 //!< type id
    };

    I32 m_hello; //<! hello - 
    I32 m_helloback; //<! helloback - 
private:

};
} // end namespace HelloWorld
#endif /* HELLO_HPP_ */

