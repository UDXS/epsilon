#include "py/obj.h"
#include "py/mphal.h"
#include "modion.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_1(ion_get_key_obj, ion_key);

STATIC const mp_rom_map_elem_t ion_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ion) },
    { MP_ROM_QSTR(MP_QSTR_get_key), (mp_obj_t)&ion_get_key_obj }
};

STATIC MP_DEFINE_CONST_DICT(ion_module_globals, ion_module_globals_table);

const mp_obj_module_t ion_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&ion_module_globals,
};