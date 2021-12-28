from common import log_mod
import functools


class Logdeco:
    module_name = "PARSE"

    def __init__(self, f):
        self.func = f

    def __call__(self, *args, **kwargs):
        log_mod.set_log(self.module_name, self.func.__name__ + ' Entry...', log_mod.Logtype_PFF)
        log_mod.set_log(self.module_name, self.func.__name__ + ' Parameter, ' + str(args), log_mod.Logtype_INF)

        try:
            print(*args)
            r = self.func(self.func.__self__,*args, **kwargs)
            return r
        except Exception as ex:
            log_mod.set_log(self.module_name, self.func.__name__ + ' exception ' + str(ex), log_mod.Logtype_ERR)
            print("Exception")

        log_mod.set_log(self.module_name, self.func.__name__ + ' Exit...', log_mod.Logtype_PFF)

