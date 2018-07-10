! { dg-do run }
! { dg-xfail-run-if "TODO" { openacc_nvidia_accel_selected } { "-O0" "-O1" } { "" } }

program main
  use openacc
  implicit none

  integer :: i, j
  integer, parameter :: N = 1000000
  integer, parameter :: nprocs = 2
  integer :: k(nprocs)

  k(:) = 0

  !$acc data copy (k(1:nprocs))
    do j = 1, nprocs
      !$acc parallel async (j)
        do i = 1, N
          k(j) = k(j) + 1
        end do
      !$acc end parallel
    end do
  !$acc end data

  if (acc_async_test (1) .neqv. .TRUE.) call abort
  if (acc_async_test (2) .neqv. .TRUE.) call abort

  call acc_wait_all_async (nprocs + 1)

  if (acc_async_test (nprocs + 1) .neqv. .TRUE.) call abort

  call acc_wait_all ()

end program
