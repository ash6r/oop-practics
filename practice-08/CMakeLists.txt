cmake_minimum_required(VERSION 4.1)

project("practice-08" CXX)

add_executable("${PROJECT_NAME}")
target_compile_options("${PROJECT_NAME}" PUBLIC -stdlib=libc++)
target_link_options("${PROJECT_NAME}" PUBLIC -stdlib=libc++ -L/opt/homebrew/opt/llvm/lib/c++ -Wl,-rpath,/opt/homebrew/opt/llvm/lib/c++)
target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_sources("${PROJECT_NAME}"
	PRIVATE
		"main.cpp"
	PRIVATE FILE_SET "modules" TYPE CXX_MODULES FILES
		"collections/collections.api.cppm"
		"collections/collections.list.cppm"
		"collections/collections.hash-set.cppm"
		"collections/collections.dictionary.cppm"
		"collections/collections.stack.cppm"
		"collections/collections.queue.cppm"
)
