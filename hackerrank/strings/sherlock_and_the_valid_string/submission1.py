def isValid(s):
    def countTimes(n, arr):
        count = 0
        for val in arr:
            if val == n:
                count += 1
        return count

    d = {}
    for letter in s:
        if letter not in d:
            d[letter] = 1
        else:
            d[letter] += 1

    unique = set(d.values())
    if len(unique) <= 2:
        #print(unique)
        if len(unique) == 1:
            return 'YES'
        a, b = list(unique)
        # No letter has count 1, but only one letter has count of (the other count + 1)
        if (abs(a - b) == 1
                and (countTimes(a, d.values()) == 1 or countTimes(b, d.values()) == 1)):
            return 'YES'
        # only one letter has count 1
        if abs(a - b) != 1 and countTimes(1, d.values()) == 1:
            return 'YES'
    return 'NO'


print(isValid("aabbccddeefghi")) #NO
print(isValid("aabbcd")) #NO
print(isValid("abcdefghhgfedecba"))#YES
print(isValid("xxxaabbccrry"))
print(isValid("ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd"))
