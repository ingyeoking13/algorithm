class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        ps = [*pattern]
        ss = s.split(' ')
        d = {}
        if len(ps) != len(ss):
            return False

        for (p, s) in zip(ps, ss):
            if p in d.keys():
                if s == d[p]:
                    continue
                else:
                    return False
            else: 
                if s in d.values():
                    return False
                d[p] = s

        return True