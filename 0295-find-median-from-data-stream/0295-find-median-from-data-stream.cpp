// class MedianFinder {
// public:

//     int n;
//     double med;
//     multiset<int> st;
//     multiset<int>::iterator it;
//     MedianFinder() {
//         n = 0;
//         set;
//         med = 0;
//             st.insert(-1);
//         it = st.begin();

//     }
    
//     void addNum(int num) {
//         n++;
//         st.insert(num);
//         if(n%2 == 0){            // ye solution bhi ho sakta he lekin ek iterator ki value 
//             int a = *it;         // change nhi hoti, naye iterator add ho jate he jisse apne
//             int b = *(++it); it--;   // ko value compare karke apne it ko aage, piche karna
//             med = (a + b)/2.0;       // hota.....
//         }else{                       // jo ki bahut confucing ja rha he.
//             it++;
//             med = *it;
//         }
//     }
    
//     double findMedian() {
//         int x = 100000*med;
//         med = double(x)/100000.0;
//         return med;
//     }
// };

class MedianFinder {
public:

	priority_queue<int> increasing;
	priority_queue<int, std::vector<int>, greater<int>> decreasing;
	int n = 0;
    MedianFinder() {

    }
    
    void addNum(int num) {
    	n++;
    	if(n&1){
    		decreasing.push(num);
    		increasing.push(decreasing.top());
    		decreasing.pop();
    	}else{
    		increasing.push(num);
    		decreasing.push(increasing.top());
    		increasing.pop();
    	}
    }
    
    double findMedian() {
    	if(n&1) return increasing.top();
    	return (decreasing.top() + increasing.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */