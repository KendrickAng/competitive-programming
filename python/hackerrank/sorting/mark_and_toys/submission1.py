def maximumToys(prices, k):
    prices.sort()
    toys = 0
    for price in prices:
        if k < price:
            break
        k -= price
        toys += 1
    return toys

print(maximumToys([1,12,5,111,200,1000,10], 50))