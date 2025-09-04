def bubble_sort(array)
  unsorted_until_index = array.length - 1
  sorted = false

  while !sorted
    sorted = true
    (0...unsorted_until_index).each do |i|
      if array[i] > array[i+1]
        array[i], array[i+1] = array[i+1], array[i]
        sorted = false
      end
    end
    unsorted_until_index -= 1
  end

  array
end

p bubble_sort([3, 10, 5, 4, 2])
