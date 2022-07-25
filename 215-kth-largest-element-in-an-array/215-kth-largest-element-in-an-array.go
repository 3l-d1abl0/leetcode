func heapify(arr []int, idx int, N int) {

	root := idx
	for root*2+1 < N {

		child := root*2 + 1

		if child+1 < N && arr[child+1] > arr[child] {
			child++
		}

		if arr[child] > arr[root] {
			arr[child], arr[root] = arr[root], arr[child]

			root = child
		} else {
			return
		}
	}
}

func sortHeap(arr []int, k int, lidx int, ridx int) {

	for idx := 0; idx < k-1; idx++ {
		arr[0], arr[ridx-idx] = arr[ridx-idx], arr[0]
		heapify(arr[:], 0, ridx-idx)
	}

}

func buildHeap(arr []int, lidx int, ridx int) {

	//start from last iternal node
	N := ridx + 1

	for idx := (N - 2) / 2; idx >= 0; idx-- {
		heapify(arr[:], idx, N)
	}
}

func heapsort(arr []int, k int, lidx int, ridx int) int {

	buildHeap(arr[:], lidx, ridx)
	sortHeap(arr[:], k, lidx, ridx)
    
    return arr[0]
}

func findKthLargest(nums []int, k int) int {
    
    return heapsort(nums[:], k, 0, len(nums)-1)
    
    //return nums[k] 
}