// Copyright 2017-2018 VMware, Inc.
// SPDX-License-Identifier: BSD-2-Clause
//
// The BSD-2 license (the License) set forth below applies to all parts of the
// Cascade project.  You may not use this file except in compliance with the
// License.
//
// BSD-2 License
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef CASCADE_SRC_VERILOG_AST_GENERATE_BLOCK_H
#define CASCADE_SRC_VERILOG_AST_GENERATE_BLOCK_H

#include <cassert>
#include "src/verilog/ast/types/identifier.h"
#include "src/verilog/ast/types/macro.h"
#include "src/verilog/ast/types/many.h"
#include "src/verilog/ast/types/maybe.h"
#include "src/verilog/ast/types/module_item.h"
#include "src/verilog/ast/types/node.h"
#include "src/verilog/ast/types/scope.h"

namespace cascade {

class GenerateBlock : public Node, public Scope {
  public:
    // Constructors:
    GenerateBlock(Maybe<Identifier>* id__, bool scope__, Many<ModuleItem>* items__);
    ~GenerateBlock() override;

    // Node Interface:
    NODE(GenerateBlock, TREE(id), LEAF(scope), TREE(items))
    // Get/Set:
    TREE_GET_SET(id)
    LEAF_GET_SET(scope)
    TREE_GET_SET(items)

  private:
    TREE_ATTR(Maybe<Identifier>*, id);
    LEAF_ATTR(bool, scope);
    TREE_ATTR(Many<ModuleItem>*, items);
};

inline GenerateBlock::GenerateBlock(Maybe<Identifier>* id__, bool scope__, Many<ModuleItem>* items__) : Node() {
  parent_ = nullptr;
  TREE_SETUP(id);
  LEAF_SETUP(scope);
  TREE_SETUP(items);
  next_supdate_ = 0;
}

inline GenerateBlock::~GenerateBlock() {
  TREE_TEARDOWN(id);
  LEAF_TEARDOWN(scope);
  TREE_TEARDOWN(items);
}

} // namespace cascade 

#endif
