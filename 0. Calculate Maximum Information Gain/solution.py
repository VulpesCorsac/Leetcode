import numpy as np
from scipy.stats import entropy

class Solution:
    def calculateEntropy(self, input: List[int]) -> float:
        value, counts = np.unique(input, return_counts=True)
        return entropy(counts, base=2)

    def calculateMaxInfoGain(self, petal_length: List[float], species: List[str]) -> float:
        size = len(species)

        indices_sorted_petal_length = [i[0] for i in sorted(enumerate(petal_length), key= lambda x: x[1])]
        sorted_species = [species[i] for i in indices_sorted_petal_length]

        h = self.calculateEntropy(sorted_species)
        max_inf_gain = 0

        for i in range(1, len(species)):
            l1 = sorted_species[:i]
            l2 = sorted_species[i:]
            h1 = self.calculateEntropy(l1)
            h2 = self.calculateEntropy(l2)
            inf_gain = h - h1*len(l1)/size - h2*len(l2)/size

            if inf_gain > max_inf_gain:
                max_inf_gain = inf_gain

        return max_inf_gain
