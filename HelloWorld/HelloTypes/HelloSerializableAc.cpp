#include <HelloWorld/HelloTypes/HelloSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/EightyCharString.hpp>
#endif
#include <cstring>
namespace HelloWorld {
// public methods

Hello::Hello(void): Serializable() {

}

Hello::Hello(const Hello& src) : Serializable() {
    this->set(src.m_hello, src.m_helloback);
}

Hello::Hello(const Hello* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_hello, src->m_helloback);
}

Hello::Hello(I32 hello, I32 helloback) : Serializable() {
    this->set(hello, helloback);
}

const Hello& Hello::operator=(const Hello& src) {
    this->set(src.m_hello, src.m_helloback);
    return src;
}

bool Hello::operator==(const Hello& src) const {
    return (
        (src.m_hello == this->m_hello) &&
        (src.m_helloback == this->m_helloback) &&
        true);
}

void Hello::set(I32 hello, I32 helloback) {
    this->m_hello = hello;
    this->m_helloback = helloback;
}

I32 Hello::gethello(void) {
    return this->m_hello;
}

I32 Hello::gethelloback(void) {
    return this->m_helloback;
}

void Hello::sethello(I32 val) {
    this->m_hello = val;
}
void Hello::sethelloback(I32 val) {
    this->m_helloback = val;
}
Fw::SerializeStatus Hello::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID    
    // serialize type ID
    stat = buffer.serialize((U32)Hello::TYPE_ID);
#endif    

    stat = buffer.serialize(this->m_hello);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_helloback);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus Hello::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID    
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != Hello::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif    

    stat = buffer.deserialize(this->m_hello);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_helloback);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void Hello::toString(Fw::StringBase& text) const {
    
    static const char * formatString = 
       "("
       "hello = %d, "
       "helloback = %d"
       ")";
       
    // declare strings to hold any serializable toString() arguments

       
    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_hello
       ,this->m_helloback
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
    
    text = outputString;           
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const Hello& obj) {
        Fw::EightyCharString str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace HelloWorld
