"""
This script parses values from config.json for use in the build environment as value macros.
"""
import json
from platformio import util

try:
    Import("projenv")
    mode = "local"
except:
    Import("env")
    mode = "global"



def parseConfig(d, prefix=''):
    if prefix is not '':
        prefix += '_'
    result = []
    for key in d:
        t = type(d[key])
        if t is dict:
            result.extend(parseConfig(d[key], key))
            continue
        elif t in (str, unicode):
            if d[key] == "":
                result.append(str(prefix+key))
                continue
            else:
                val = "\\\"%s\\\"" % d[key]
        elif t is bool:
            val = str(d[key]).lower()
        else:
            val = d[key]
        result.append((str(prefix+key), val))
    return result


cfg = []
with open('config.json') as f:
    data = json.load(f)
    if mode in data:
        cfg.extend(parseConfig(data[mode]))


if cfg:
    print("Injecting " + str(len(cfg)) + " %s build environment config values." % mode)
    print cfg
    if mode == "local":
        projenv.Append(CPPDEFINES=cfg)
    else:
        env.Append(CPPDEFINES=cfg)
else:
    print("No %s build environment config values found. Skipping config injection." % mode)
