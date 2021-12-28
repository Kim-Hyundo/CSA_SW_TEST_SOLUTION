from common import log_mod
import functools


module_name = "PARSE"

def Logdeco(f):
    @functools.wraps(f)
    def wrapper(*args, **kwargs):
        log_mod.set_log(module_name, f.__name__ + ' Entry...', log_mod.Logtype_INF)
        log_mod.set_log(module_name, f.__name__ + ' Parameter, ' + str(args), log_mod.Logtype_INF)

        try:
            ret = f(*args, **kwargs)
            return ret
        except Exception as ex:
            log_mod.set_log(module_name, f.__name__ + ' exception ' + str(ex), log_mod.Logtype_ERR)
            print("Exception")

        log_mod.set_log(module_name, f.__name__ + ' Exit...', log_mod.Logtype_PFF)
    return wrapper

