


##### ENGINGE

```c
struct engine_st {
    const char *id;
    const char *name;

    const RSA_METHOD     *rsa_meth;
    const DSA_METHID     *dsa_meth;
    const ECDH_METHOD   *ecdh_meth;
    const ECDSA_METHOD *ecdsa_meth;
    const RAND_METHOD   *rand_meth;
    const STORE_METHOD *store_meth;

    int flags;
    int struct_ref;
    int funct_ref;
    CRYPTO_EX_DATA ex_data;
    struct engine_st *prev;
    struct engine_st *next;
};
```