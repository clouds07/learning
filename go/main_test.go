package main

import (
	"fmt"
	"testing"
)

func placeOrder(productID string, quantity int, accountBalance float64) (bool, float64) {
	if amountInStock(productID) == 0 {
		return false, accountBalance
	}
	if quantity > amountInStock(productID) {
		return false, accountBalance
	}
	if accountBalance < priceList(productID)*float64(quantity) {
		return false, accountBalance
	}

	return true, accountBalance - priceList(productID)*float64(quantity)
}

// Don't touch below this line

func calcPrice(productID string, quantity int) float64 {
	return priceList(productID) * float64(quantity)
}

func priceList(productID string) float64 {
	if productID == "1" {
		return 1.50
	} else if productID == "2" {
		return 2.25
	} else if productID == "3" {
		return 3.00
	} else if productID == "4" {
		return 1.00
	} else if productID == "5" {
		return 2.50
	} else if productID == "6" {
		return 8.99
	} else if productID == "7" {
		return 22.50
	} else if productID == "8" {
		return 50.00
	} else if productID == "9" {
		return 999.99
	} else {
		return 0.00
	}
}

func amountInStock(productID string) int {
	if productID == "1" {
		return 11
	} else if productID == "2" {
		return 25
	} else if productID == "3" {
		return 4
	} else if productID == "4" {
		return 6
	} else if productID == "5" {
		return 50
	} else if productID == "6" {
		return 2
	} else if productID == "7" {
		return 0
	} else if productID == "8" {
		return 99
	} else if productID == "9" {
		return 1
	} else {
		return 0
	}
}

func Test(t *testing.T) {
	type testCase struct {
		productID      string
		quantity       int
		accountBalance float64
		expected_1     bool
		expected_2     float64
	}
	tests := []testCase{
		{"1", 2, 226.95, true, 223.95},
		{"2", 4, 459, true, 450},
		{"3", 4, 1185.2, true, 1173.2},
		{"4", 5, 0, false, 0},
		{"5", 50, 195, true, 70},
	}
	if withSubmit {
		tests = append(tests, []testCase{
			{"6", 0, 100, true, 100},
			{"7", 7421, 210.24, false, 210.24},
			{"8", 55, 24.5, false, 24.5},
			{"9", 1, 999.99, true, 0},
		}...)
	}

	passCount := 0
	failCount := 0

	for _, test := range tests {
		output_1, output_2 := placeOrder(
			test.productID,
			test.quantity,
			test.accountBalance,
		)
		if output_1 != test.expected_1 || output_2 != test.expected_2 {
			failCount++
			t.Errorf(`---------------------------------
Inputs:     (%v, %v, %.2f)
Expecting:  (%v, %.2f)
Actual:     (%v, %.2f)
Fail`, test.productID, test.quantity, test.accountBalance, test.expected_1, test.expected_2, output_1, output_2)
		} else {
			passCount++
			fmt.Printf(`---------------------------------
Inputs:     (%v, %v, %.2f)
Expecting:  (%v, %.2f)
Actual:     (%v, %.2f)
Pass
`, test.productID, test.quantity, test.accountBalance, test.expected_1, test.expected_2, output_1, output_2)
		}
	}

	fmt.Println("---------------------------------")
	fmt.Printf("%d passed, %d failed\n", passCount, failCount)
}

// withSubmit is set at compile time depending
// on which button is used to run the tests
var withSubmit = true
