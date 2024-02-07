class Solution(object):
    def groupAnagrams(self, strs):
        anagrams_map = defaultdict(list)
        for s in strs:
            sorted_str = ''.join(sorted(s))
            anagrams_map[sorted_str].append(s)

        grouped_anagrams = list(anagrams_map.values())
        return grouped_anagrams
            
        