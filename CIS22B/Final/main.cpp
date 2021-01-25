// Rohith Vishwajith
// CIS22B
// main.cpp
// IDE: XCode
// 12/7/2020

// STEP 1: Check for invalid arguments
// STEP 2: Find the length of the whole list
// STEP 3: Check if the argument is in the bounds of the list length
// STEP 4: Find the desired node and the previous node
// STEP 5: The node pointing to the current node should now point to the currentNode's target
// STEP 6: The desired node should point to the first node
// STEP 7: The setinal node should point to the current node
bool FriendsList::move(int index) {
    
    // STEP 1:
    // This is either the first node or an invalid argument, exit if necessary
    if(index <= 1 || head == NULL) {
        return false;
    }
    
    // STEP 2:
    // Find the list length
    // Look for the desired node
    ListNode *cur = this->head->next;
    
    int length = 0;
    
    while(cur != NULL) {
        length++;
        cur = this->cur->next;
    }
    
    // STEP 3:
    // Check if the index is too great, exit if necessary
    if(index >= length) {
        return false;
    }
    
    // STEP 4:
    // Find the wanted node and its previous node
    ListNode *desired = this->head->next;
    ListNode *prev;
    int i = 0;
    
    // we know index is at least 2 here
    while(i < index) {
        desired = desired->next;
        prev = desired;
        ++i;
    }
    
    // STEP 5:
    // Set the previous node's target to the desired node's target
    prev->next = desired->next;
    
    // STEP 6:
    // Make the desired node point to the first node
    desired->next = this->head->next;
    
    // STEP 7:
    // Make the sentinel node point to the desired node
    this->head->next = desired;
    return true;
}
