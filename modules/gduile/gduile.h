#ifndef GDUILE_H
#define GDUILE_H

#include "core/script_language.h"

class GDuileScript: public Script {
  GDCLASS(GDuileScript, Script);
  bool tool;
  bool valid;
  Script *_base;
  String source_code;

  friend class GDuileLang;

public:
  virtual bool is_valid() const { return valid; }

  bool is_tool() const { return tool; }

  virtual bool can_instance() const;
  virtual Ref<Script> get_base_script() const;
  virtual StringName get_instance_base_type() const;
  virtual ScriptInstance *instance_create(Object *p_this);
  virtual PlaceHolderScriptInstance *placeholder_instance_create(Object *p_this);
  virtual bool instance_has(const Object *p_this) const;

  virtual bool has_source_code() const;
  virtual String get_source_code() const;
  virtual void set_source_code(const String &p_code);
  virtual void update_exports();

  virtual Error reload(bool p_keep_state = false);

  virtual void get_script_method_list(List<MethodInfo> *p_list) const;
  virtual bool has_method(const StringName &p_method) const;
  virtual MethodInfo get_method_info(const StringName &p_method) const;

  virtual bool has_script_signal(const StringName &p_signal) const;
  virtual void get_script_signal_list(List<MethodInfo> *r_signals) const;

  virtual void get_script_property_list(List<PropertyInfo> *p_list) const;
  virtual bool get_property_default_value(const StringName &p_property, Variant &r_value) const;
  virtual ScriptLanguage *get_language() const;

  virtual int get_member_line(const StringName &p_method) const { return -1; }

  virtual void get_constants(Map<StringName, Variant> *p_constants);
  virtual void get_members(Set<StringName> *p_members);

  GDuileScript();
  ~GDuileScript();
};

class GDuileLang : public ScriptLanguage {

  static GDuileLang *singleton;

  friend class GDuileScript;
  
public:
  String get_name() const ;

  /* LANGUAGE FUNCTIONS */
  void init();
  String get_type() const ;
  String get_extension() const ;
  Error execute_file(const String &p_path) ;
  void finish() ;

  /* EDITOR FUNCTIONS */
  void get_reserved_words(List<String> *p_words) const ;
  void get_comment_delimiters(List<String> *p_delimiters) const ;
  void get_string_delimiters(List<String> *p_delimiters) const ;
  Ref<Script> get_template(const String &p_class_name, const String &p_base_class_name) const ;
  bool validate(const String &p_script, int &r_line_error, int &r_col_error, String &r_test_error, const String &p_path = "", List<String> *r_functions = NULL, List<ScriptLanguage::Warning> *r_warnings = NULL, Set<int> *r_safe_lines = NULL) const ;
  Script *create_script() const ;
  bool has_named_classes() const ;
  bool supports_builtin_mode() const ;
  int find_function(const String &p_function, const String &p_code) const ;
  String make_function(const String &p_class, const String &p_name, const PoolStringArray &p_args) const ;

  void auto_indent_code(String &p_code, int p_from_line, int p_to_line) const ;
  void add_global_constant(const StringName &p_variable, const Variant &p_value) ;
  
  /* DEBUGGER FUNCTIONS */

  String debug_get_error() const ;
  int debug_get_stack_level_count() const ;
  int debug_get_stack_level_line(int p_level) const ;
  String debug_get_stack_level_function(int p_level) const ;
  String debug_get_stack_level_source(int p_level) const ;
  void debug_get_stack_level_locals(int p_level, List<String> *p_locals, List<Variant> *p_values, int p_max_subitems = -1, int p_max_depth = -1) ;
  void debug_get_stack_level_members(int p_level, List<String> *p_members, List<Variant> *p_values, int p_max_subitems = -1, int p_max_depth = -1) ;
  void debug_get_globals(List<String> *p_globals, List<Variant> *p_values, int p_max_subitems = -1, int p_max_depth = -1) ;
  String debug_parse_stack_level_expression(int p_level, const String &p_expression, int p_max_subitems = -1, int p_max_depth = -1) ;

  void reload_all_scripts() ;
  void reload_tool_script(const Ref<Script> &p_script, bool p_soft_reload) ;
  /* LOADER FUNCTIONS */

  void get_recognized_extensions(List<String> *p_extensions) const;
  void get_public_functions(List<MethodInfo> *p_functions) const;
  void get_public_constants(List<Pair<String, Variant> > *p_constants) const;

  void profiling_start();
  void profiling_stop();

  int profiling_get_accumulated_data(ProfilingInfo *p_info_arr, int p_info_max);
  int profiling_get_frame_data(ProfilingInfo *p_info_arr, int p_info_max);

  GDuileLang();
  ~GDuileLang();
};


#endif /* GDUILE_H */
