def has_duplicate_value(array)
  existing_numbers = []
  (0...array.length).each do |i|
    if existing_numbers[array[i]] == 1
      return true
    else
      existing_numbers[array[i]] = 1
    end
  end
  return false
end

pp has_duplicate_value([1,2,3,4,5,6,7,8,9])
