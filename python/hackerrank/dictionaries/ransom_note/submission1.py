def checkMagazine(magazine, note):
    # generate dict
    magazineWords = {}
    for word in magazine:
        if word in magazineWords:
            magazineWords[word] += 1
        else:
            magazineWords[word] = 1
    # check dict
    for word in note:
        if word not in magazineWords or magazineWords[word] <= 0:
            print('No')
            return
        magazineWords[word] -= 1
    print('Yes')

print(checkMagazine(['give','me','one','grand','today','night'],['give','one','grand','today']))
print(checkMagazine(['ive','got','a','lovely','bunch','of','coconuts'], ['ive','got','some','coconuts']))