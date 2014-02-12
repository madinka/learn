loop = 1
while loop == 1:
    response = raw_input("Enter something or 'quit' to end => ")
    if response == 'quit':
        print 'quitting'
        loop = 0
    else:
        print 'You typed %s' % response
