#include "register_types.h"
#include "core/class_db.h"
#include "gduile.h"

GDuileLang *script_language_gduile = NULL;

void register_gduile_types() {
  script_language_gduile = memnew(GDuileLang);
  ScriptServer::register_language(script_language_gduile);
}

void unregister_gduile_types() {
  ScriptServer::unregister_language(script_language_gduile);
}
