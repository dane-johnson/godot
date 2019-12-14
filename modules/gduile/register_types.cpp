#include "register_types.h"
#include "core/class_db.h"
#include "gduile.h"

GDuileLang *script_language_gduile = NULL;
Ref<ResourceFormatLoaderGDuile> resource_loader_gduile;
Ref<ResourceFormatSaverGDuile> resource_saver_gduile;

void register_gduile_types() {
  ClassDB::register_class<GDuileScript>();
  script_language_gduile = memnew(GDuileLang);
  ScriptServer::register_language(script_language_gduile);

  resource_loader_gduile.instance();
  ResourceLoader::add_resource_format_loader(resource_loader_gduile);

  resource_saver_gduile.instance();
  ResourceSaver::add_resource_format_saver(resource_saver_gduile);
}

void unregister_gduile_types() {
  ScriptServer::unregister_language(script_language_gduile);
}
