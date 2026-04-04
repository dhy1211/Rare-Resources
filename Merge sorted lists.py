# 1. BẠN PHẢI TỰ ĐỊNH NGHĨA LISTNODE Ở ĐÂY ĐỂ VS CODE HIỂU
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 2. SAU ĐÓ MỚI ĐẾN ĐOẠN CODE GIẢI BÀI CỦA BẠN
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        nodes = []
        
        for l in [list1, list2]:
            while l:
                nodes.append(l.val)
                l = l.next
                
        nodes.sort()
        
        dummy = ListNode(0)
        current = dummy
        for val in nodes:
            current.next = ListNode(val)
            current = current.next
            
        return dummy.next