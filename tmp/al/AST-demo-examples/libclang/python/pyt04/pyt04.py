import clang.cindex

index = clang.cindex.Index.create()
translation_unit = index.parse('my_source.cpp', args=['-std=c++17'])

for i in translation_unit.get_tokens(extent=translation_unit.cursor.extent):
    # It's my code:
    if i.kind != "PUNCTUATION": 
        print (i.kind)
        typename = i.spelling
        print(
            'Type name: %s [line=%s, col=%s]' % (
            typename, i.location.line, i.location.column)
            )

