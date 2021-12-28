import pickle

def object_file_dump(filename, data_dump, mode):
    try:

        with open(filename, mode) as f:
            pickle.dump(data_dump, f, protocol=2)

    except:
        return False

    return True

def object_file_load(filename, mode):
    data_dump=[]

    try:
        with open(filename, mode) as f:
            data_dump = pickle.load(f)

    except Exception as ex:
        return False

    return data_dump
