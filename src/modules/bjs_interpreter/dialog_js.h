#ifndef __DIALOG_JS_H__
#define __DIALOG_JS_H__
#include <duktape.h>

duk_ret_t native_dialogMessage(duk_context *ctx);
duk_ret_t native_dialogError(duk_context *ctx);
duk_ret_t native_dialogPickFile(duk_context *ctx);
duk_ret_t native_dialogChoice(duk_context *ctx);
duk_ret_t native_dialogViewFile(duk_context *ctx);
duk_ret_t native_dialogViewText(duk_context *ctx);
duk_ret_t native_dialogCreateTextViewer(duk_context *ctx);

#endif
