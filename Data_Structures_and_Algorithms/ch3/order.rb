things = ['apples', 'baboons', 'cribe', 'dulcimers']

things.each do |thing|
  p "Here's a thing: #{thing}"
end

def is_prime(number)
  return false if number <= 1
  (2..number).each do |i|
    if number % i == 0 && i != number
      return false
    end
  end
  return true
end

p is_prime(11)
