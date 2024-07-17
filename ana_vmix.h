      ! modify to your liking
      ! Non-trivial example in the Filament example
      ! Cubic profile for filament case


      integer :: i,j,k
      real    :: cff
      real    :: hbl,ssgm

      hbl = 70.0  ! match the initial mixed layer depth

      if (FIRST_TIME_STEP) then
        do k=0,nz
          do j=0,ny+1
            do i=0,nx+1
              ssgm=(z_w(i,j,nz)-z_w(i,j,k))/hbl
              if (ssgm < 1.) then
                !zero at surface
                cff = ssgm*(1.-ssgm)**2
              else
                cff=0
              endif

     
	      !bak set in .in file, 0.14805 is max
              Akv(i,j,k) = cff * Akv_bak / 0.14805
              Akt(i,j,k,itemp) = cff * Akt_bak(itemp) / 0.14805

#  ifdef SALINITY
              Akt(i,j,k,isalt)=Akt_bak(isalt)
#  endif

	    !TESTING CONSTANT MIXING PROFILE
	    !Akv(i,j,k) = Akv_bak
	    !Akt(i,j,k,itemp) = Akt_bak(itemp)
            enddo
          enddo
        enddo
      endif

