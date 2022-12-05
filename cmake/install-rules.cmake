install(
    TARGETS ray_tracing_examp_exe
    RUNTIME COMPONENT ray_tracing_examp_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
