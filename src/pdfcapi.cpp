/*
 * Copyright 2023 Jussi Pakkanen
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <a4pdf.h>
#include <pdfgen.hpp>
#include <pdfpagebuilder.hpp>

using namespace A4PDF;

A4PDF_Options *a4pdf_options_create() {
    return reinterpret_cast<A4PDF_Options *>(new PdfGenerationData());
}

void a4pdf_options_destroy(A4PDF_Options *opt) {
    delete reinterpret_cast<PdfGenerationData *>(opt);
}

int32_t a4pdf_options_set_title(A4PDF_Options *opt, const char *utf8_title) {
    reinterpret_cast<PdfGenerationData *>(opt)->title = utf8_title;
    return 0;
}

A4PDF_Generator *a4pdf_generator_create(const char *filename, const A4PDF_Options *options) {
    auto opts = reinterpret_cast<const PdfGenerationData *>(options);
    return reinterpret_cast<A4PDF_Generator *>(new PdfGen(filename, *opts));
}

void a4pdf_generator_destroy(A4PDF_Generator *generator) {
    delete reinterpret_cast<PdfGen *>(generator);
}

void a4pdf_generator_new_page(A4PDF_Generator *gen_c) {
    reinterpret_cast<PdfGen *>(gen_c)->new_page();
}

const char *a4pdf_error_message(int32_t error_code) {
    if(error_code == 0)
        return "No error";
    return "Error messages not implemented yet";
}
