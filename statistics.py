class StatisticsCalculator:
    def __init__(self, data):
        if not data:
            raise ValueError("Data list cannot be empty")
        self.data = data

    def calculate_mean(self):
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        if n % 2 == 0:
            return (sorted_data[n//2 - 1] + sorted_data[n//2]) / 2
        return sorted_data[n//2]

    def calculate_mode(self):
        freq = {}
        for num in self.data:
            freq[num] = freq.get(num, 0) + 1
        max_count = max(freq.values())
        return [k for k, v in freq.items() if v == max_count]

if __name__ == "__main__":
    data = [1,2,2,3,4,5,2]
    calc = StatisticsCalculator(data)

    print(f"Mean: {calc.calculate_mean():.2f}")
    print(f"Median: {calc.calculate_median():.2f}")
    print(f"Mode(s): {calc.calculate_mode()}")
