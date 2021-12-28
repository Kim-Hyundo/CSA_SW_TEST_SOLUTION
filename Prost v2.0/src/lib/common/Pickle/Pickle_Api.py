import pickle

def object_file_dump(filename, data_dump, mode):
    try:
        with open(filename, mode) as f:
            pickle.dump(data_dump, f, protocol=pickle.HIGHEST_PROTOCOL)
            #pickle.dump(data_dump, f)
    except Exception as e:
        return e
    return 'ok'

def object_file_load(filename, mode):
    data_dump=[]
    try:    
        with open(filename, mode) as f:
            data_dump = pickle.load(f)
    except Exception as e:
        return e
    return data_dump
