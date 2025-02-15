/* Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include "paddle/phi/core/selected_rows.h"

namespace phi {

template <>
const TypeInfo<phi::TensorBase>
    TypeInfoTraits<phi::TensorBase, SelectedRows>::kType =
        RegisterStaticType<phi::TensorBase>(SelectedRows::name());

SelectedRows::SelectedRows(const std::vector<int64_t>& rows,
                           const int64_t& height)
    : impl_(std::make_shared<phi::SelectedRowsImpl>(rows, height)) {}

SelectedRows::SelectedRows()
    : impl_(std::make_shared<phi::SelectedRowsImpl>()) {}

void SelectedRows::set_type(const DataType dtype) { impl_->set_type(dtype); }

void SelectedRows::set_layout(const DataLayout layout) {
  impl_->set_layout(layout);
}

}  // namespace phi
