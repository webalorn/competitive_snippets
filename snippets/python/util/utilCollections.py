def argmin(l): return l.index(min(l))
def argmax(l): return l.index(max(l))

def dict_min(d): return min(d.values())
def dict_max(d): return max(d.values())
def dict_argmin(d):m = dict_min(d);return [el for el, v in d.items() if v==m][0]
def dict_argmax(d):m = dict_max(d);return [el for el, v in d.items() if v==m][0]