set_toolchains("clang")
set_languages("c++20")
set_warnings("all", "extra")
add_cxflags("-Werror", "-pedantic-errors")

for _, dir in ipairs(os.dirs("*")) do
    local solution = path.join(dir, "solution.cpp")
    if os.isfile(solution) then
        target(dir)
            set_kind("binary")
            add_files(solution)
    end
end
