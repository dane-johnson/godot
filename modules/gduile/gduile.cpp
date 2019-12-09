#include "gduile.h"

String GDuileLang::get_name() const {
  return "GDuile";
}

// Language Functions
void GDuileLang::init() {
  // TODO
}

String GDuileLang::get_type() const {
  return "GDuile";
}

String GDuileLang::get_extension() const {
  return "scm";
}

void GDuileLang::finish() {
  // TODO
}

// Editor Functions
void GDuileLang::get_reserved_words(List<String> *p_words) const {}
void GDuileLang::get_comment_delimiters(List<String> *p_delimiters) const {}
void GDuileLang::get_string_delimiters(List<String> *p_delimiters) const {}
Ref<Script> GDuileLang::get_template(const String &p_class_name, const String &p_base_class_name) const { return NULL; }
bool GDuileLang::validate(const String &p_script, int &r_line_error, int &r_col_error, String &r_test_error, const String &p_path, List<String> *r_functions, List<ScriptLanguage::Warning> *r_warnings, Set<int> *r_safe_lines) const { return true; }
Script* GDuileLang::create_script() const { return NULL; }
bool GDuileLang::has_named_classes() const { return false; }
bool GDuileLang::supports_builtin_mode() const { return false; }
int GDuileLang::find_function(const String &p_function, const String &p_code) const { return 0; }
String GDuileLang::make_function(const String &p_class, const String &p_name, const PoolStringArray &p_args) const { return p_name; }

// Loader Functions
void GDuileLang::get_recognized_extensions(List<String> *p_extentions) const {}
void GDuileLang::get_public_functions(List<MethodInfo> *p_functions) const {}
void GDuileLang::get_public_constants(List<Pair<String, Variant>> *p_constants) const {}

void GDuileLang::profiling_start() {}
void GDuileLang::profiling_stop() {}

int GDuileLang::profiling_get_accumulated_data(ProfilingInfo *p_info_arr, int p_info_max) { return 0; }
int GDuileLang::profiling_get_frame_data(ProfilingInfo *p_info_arr, int p_info_max) { return 0; }

GDuileLang::GDuileLang() {
  singleton = this;
}

GDuileLang::~GDuileLang() {
  singleton = NULL;
}
