def test(arr):
    arr = []
    while head:
        arr.append(head.val)
        head = head.next
    
    while True:
        isChanged = False
        i = 1
        while i < len(arr):
            if arr[i-1] + arr[i] == 0:
                arr.pop(i-1)
                arr.pop(i-1)
                if isChanged == False:
                    isChanged = True
            i += 1
        if isChanged == False:
            break
    
    dummy = ListNode()
    curr = dummy
    for n in arr:
        curr.next = ListNode(n)
        curr = curr.next
    
    return dummy.next