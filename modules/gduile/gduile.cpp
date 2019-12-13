#include "gduile.h"

bool GDuileScript::can_instance() {
  return valid;
}

Ref<Script> get_base_script() const {
  return Ref<Script>();
}


GDuileLang *GDuileLang::singleton = NULL;

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

Error GDuileLang::execute_file(const String &p_path) {
  // I don't know what this does
  return OK;
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
Script* GDuileLang::create_script() const {
  return memnew(GDuileScript);
}
bool GDuileLang::has_named_classes() const { return false; }
bool GDuileLang::supports_builtin_mode() const { return false; }
int GDuileLang::find_function(const String &p_function, const String &p_code) const { return 0; }
String GDuileLang::make_function(const String &p_class, const String &p_name, const PoolStringArray &p_args) const { return p_name; }

void GDuileLang::auto_indent_code(String &p_code, int p_from_line, int p_to_line) const {}
void GDuileLang::add_global_constant(const StringName &p_variable, const Variant &p_value) {}

// Debugger Functions

String GDuileLang::debug_get_error() const { return ""; }
int GDuileLang::debug_get_stack_level_count() const { return 0; }
int GDuileLang::debug_get_stack_level_line(int p_level) const { return 0; }
String GDuileLang::debug_get_stack_level_function(int p_level) const { return ""; }
String GDuileLang::debug_get_stack_level_source(int p_level) const { return ""; }
void GDuileLang::debug_get_stack_level_locals(int p_level, List<String> *p_locals, List<Variant> *p_values, int p_max_subitems, int p_max_depth) {}
void GDuileLang::debug_get_stack_level_members(int p_level, List<String> *p_members, List<Variant> *p_values, int p_max_subitems, int p_max_depth) {}
void GDuileLang::debug_get_globals(List<String> *p_globals, List<Variant> *p_values, int p_max_subitems, int p_max_depth) {}
String GDuileLang::debug_parse_stack_level_expression(int p_level, const String &p_expression, int p_max_subitems, int p_max_depth) { return ""; }

void GDuileLang::reload_all_scripts(){}
void GDuileLang::reload_tool_script(const Ref<Script> &p_script, bool p_soft_reload){}


// Loader Functions
void GDuileLang::get_recognized_extensions(List<String> *p_extensions) const {
  p_extensions->push_back("scm");
}
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
