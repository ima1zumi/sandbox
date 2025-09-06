def selection_sort(array)
  (0...array.length).each do |i|
    lowest_number_index = i
    (i+1...array.length).each do |j|
      if array[j] < array[lowest_number_index]
        lowest_number_index = j
      end
    end

    if lowest_number_index != i
      tmp = array[i].dup
      array[i] = array[lowest_number_index]
      array[lowest_number_index] = tmp
    end
  end
  array
end

pp selection_sort([4,7,3,2,1])
