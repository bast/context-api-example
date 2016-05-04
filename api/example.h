#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED

#ifndef EXAMPLE_API
#    ifdef _WIN32
#        if defined(EXAMPLE_BUILD_SHARED) /* build dll */
#            define EXAMPLE_API __declspec(dllexport)
#        elif !defined(EXAMPLE_BUILD_STATIC) /* use dll */
#            define EXAMPLE_API __declspec(dllimport)
#        else /* static library */
#            define EXAMPLE_API
#        endif
#    else
#        if __GNUC__ >= 4
#            define EXAMPLE_API __attribute__((visibility("default")))
#        else
#            define EXAMPLE_API
#        endif
#    endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct example_context_s;
typedef struct example_context_s example_context_t;

EXAMPLE_API example_context_t *example_new();
EXAMPLE_API void example_free(example_context_t *context);
EXAMPLE_API void example_deposit(example_context_t *context, const double f);
EXAMPLE_API void example_withdraw(example_context_t *context, const double f);
EXAMPLE_API double example_get_balance(const example_context_t *context);
EXAMPLE_API void example_print_history(const example_context_t *context);

#ifdef __cplusplus
}
#endif

#endif /* EXAMPLE_H_INCLUDED */
