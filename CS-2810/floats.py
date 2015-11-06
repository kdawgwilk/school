
size=8
k=3
bias=2**(k-1)-1
print 'bias:', bias

def parse(s):
    if len(s) != size:
        print 'bad number'
        return
    sign = s[0]
    if sign == '0':
        print 'sign: positive'
    else:
        print 'sign: negative'
    expbits = s[1:k+1]
    fracbits = s[k+1:]

    # case 1: denormalized numbers
    if expbits == '0'*k:
        print 'denormalized'
        expval = 1-bias
        print 'exponent value:', expval
        fracnum = int(fracbits, 2)
        fracden = 2**len(fracbits)
        fracval = float(fracnum) / float(fracden)
        print 'fractional value:', fracnum, '/', fracden, '=', fracval
        value = (-1)**int(sign) * fracval * 2**expval
        print 'value:', value

    elif expbits != '1'*k:
        print 'normalized'
        expval = int(expbits, 2)-bias
        print 'exponent value:', expval
        fracnum = int(fracbits, 2)
        fracden = 2**len(fracbits)
        fracval = 1.0 + float(fracnum) / float(fracden)
        print 'fractional value: 1 +', fracnum, '/', fracden, '=', fracval
        value = (-1)**int(sign) * fracval * 2**expval
        print 'value:', value

    else:
        print 'special case'
        if sign == '1':
            print '-',
        if fracbits == '0'*len(fracbits):
            print 'infinity'
        else:
            print 'not a number'
