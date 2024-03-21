AEAD(Authenticated Encryption with Associated Data)


Authenticated Encryption (AE) is an encryption scheme which simultaneously assures the data confidentiality and authenticity.
Examples of encryption modes that provide AE are GCM, CCM.

Many (but not all) AE schemes allow the message to contain "associated data" (AD) which is not made confidential, 
but its integrity is protected (i.e., it is readable, but tampering with it will be detected).