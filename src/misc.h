#ifndef _MISC_H_
#define _MISC_H_


/* generic pointer */

typedef void* link_t;


/* compiler pragma */

#define PRAGMA_PADDED_BGN
#define PRAGMA_PADDED_END

#define PRAGMA_PACKED_BGN  _Pragma("pack(push, 1)")
#define PRAGMA_PACKED_END  _Pragma("pack(pop)"    )


/* syntax wrappers */

#define STATEMENT_(...)  do {__VA_ARGS__} while (0)
#define VOID_EXPR_(...)  ((__VA_ARGS__), ((void)0))


#endif
