if ARGV.length != 1
    puts "Usage: ruby myscript.rb <integer_argument>"
    exit
  end

# Number of unique random numbers you want to generate
x = ARGV[0].to_i

# Replace range_start and range_end with the desired range for random numbers
range_start = 1
range_end = 30000

# Generate an array of numbers from range_start to range_end
sequence = (range_start..range_end).to_a

# Shuffle the array to get random order of elements
shuffled_sequence = sequence.shuffle

# Select the first x numbers from the shuffled array to get unique random numbers
unique_random_numbers = shuffled_sequence.take(x)

puts unique_random_numbers.join(' ')
