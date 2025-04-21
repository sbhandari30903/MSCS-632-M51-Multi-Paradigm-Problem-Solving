from typing import List
from collections import Counter

class StatisticsCalculator:
    def __init__(self, numbers: List[int]):
        self.numbers = numbers

    def calculate_mean(self) -> float:
        """Calculate the mean (average) of the numbers."""
        return sum(self.numbers) / len(self.numbers)

    def calculate_median(self) -> float:
        """Calculate the median of the numbers."""
        sorted_numbers = sorted(self.numbers)
        n = len(sorted_numbers)
        if n % 2 == 0:
            mid1 = sorted_numbers[n//2 - 1]
            mid2 = sorted_numbers[n//2]
            return (mid1 + mid2) / 2
        else:
            return sorted_numbers[n//2]

    def calculate_mode(self) -> List[int]:
        """Calculate the mode(s) of the numbers."""
        counter = Counter(self.numbers)
        max_count = max(counter.values())
        return [num for num, count in counter.items() if count == max_count]

    def print_statistics(self) -> None:
        """Print all statistics for the numbers."""
        print(f"Numbers: {' '.join(map(str, self.numbers))}")
        print(f"Mean: {self.calculate_mean():.2f}")
        print(f"Median: {self.calculate_median():.2f}")
        print(f"Mode: {' '.join(map(str, self.calculate_mode()))}")

def main():
    # Example usage
    numbers = [1, 2, 3, 4, 5, 5, 6, 7, 8, 9]
    calculator = StatisticsCalculator(numbers)
    calculator.print_statistics()

if __name__ == "__main__":
    main() 