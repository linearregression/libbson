/*
 * Copyright 2013 10gen Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef BSON_CONTEXT_H
#define BSON_CONTEXT_H


#include "bson-macros.h"
#include "bson-types.h"


BSON_BEGIN_DECLS


/**
 * bson_context_init:
 * @context: A bson_context_t.
 * @flags: Flags for initialization.
 *
 * Initializes @context with the flags specified.
 *
 * In most cases, you want to call this with @flags set to BSON_CONTEXT_NONE
 * and create once instance per-thread.
 *
 * If you absolutely must have a single context for your application and use
 * more than one thread, then BSON_CONTEXT_THREAD_SAFE should be bitwise or'd
 * with your flags. This requires synchronization between threads.
 *
 * If you expect your hostname to change often, you may consider specifying
 * BSON_CONTEXT_DISABLE_HOST_CACHE so that gethostname() is called for every
 * OID generated. This is much slower.
 *
 * If you expect your pid to change without notice, such as from an unexpected
 * call to fork(), then specify BSON_CONTEXT_DISABLE_PID_CACHE.
 */
void
bson_context_init (bson_context_t       *context,
                   bson_context_flags_t  flags);


/**
 * bson_context_destroy:
 * @context: A bson_context_t.
 *
 * Cleans up a bson_context_t and releases any associated resources.  This
 * should be called when you are done using @context.
 */
void
bson_context_destroy (bson_context_t *context);


BSON_END_DECLS


#endif /* BSON_CONTEXT_H */
