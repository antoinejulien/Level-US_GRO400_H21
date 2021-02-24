function [Output] = anglePlaqueToAngleMoteur( anglePlaqueTop_x, anglePlaqueTop_y, hauteurPlaqueTop )
if( nargin ~= 3 ) error( 'anglePlaqueToAngleMoteur expects 3 (not %d) command line arguments.', nargin ),  end
%===========================================================================
% File: anglePlaqueToAngleMoteur.m created Feb 23 2021 by MotionGenesis 5.9.
% Portions copyright (c) 2009-2020 Motion Genesis LLC.  Rights reserved.
% MotionGenesis Student Licensee: francis trepanier. (until March 2024).
% Paid-up MotionGenesis Student licensees are granted the right
% to distribute this code for legal student-academic (non-professional) purposes only,
% provided this copyright notice appears in all copies and distributions.
%===========================================================================
% The software is provided "as is", without warranty of any kind, express or    
% implied, including but not limited to the warranties of merchantability or    
% fitness for a particular purpose. In no event shall the authors, contributors,
% or copyright holders be liable for any claim, damages or other liability,     
% whether in an action of contract, tort, or otherwise, arising from, out of, or
% in connection with the software or the use or other dealings in the software. 
%===========================================================================


%-------------------------------+--------------------------+-------------------+-----------------
% Quantity                      | Value                    | Units             | Description
%-------------------------------|--------------------------|-------------------|-----------------
hauteurAxeMoteur                =  28.63;                  % mm                  Constant
longueurBras1                   =  3;                      % in                  Constant
longueurBras2                   =  4;                      % in                  Constant
rayonDistanceAncrageEtPivot     =  148.33;                 % mm                  Constant
rayonDistanceMoteur             =  148.33;                 % mm                  Constant

angleBras1Middle                =  0.0;                    % UNITS               Guess
angleBras2Middle                =  0.0;                    % UNITS               Guess
angleBras3Middle                =  0.0;                    % UNITS               Guess
angleMot1                       =  0.0;                    % UNITS               Guess
angleMot2                       =  0.0;                    % UNITS               Guess
angleMot3                       =  0.0;                    % UNITS               Guess
anglePlaqueTop_z                =  0.0;                    % UNITS               Guess
distancePlaqueTop_x             =  0.0;                    % UNITS               Guess
distancePlaqueTop_y             =  0.0;                    % UNITS               Guess

absError                        =  1.0E-09;                %                     Absolute Error
shouldPrintToScreen             =  1;                      % NoUnits             0 or 1
shouldPrintToFile               =  1;                      % NoUnits             0 or 1
%-------------------------------+--------------------------+-------------------+-----------------

% Unit conversions.  UnitSystem: kg, meter, second.
DEGtoRAD = pi / 180.0;
RADtoDEG = 180.0 / pi;
hauteurAxeMoteur = hauteurAxeMoteur * 0.001;               %  Converted from mm 
longueurBras1 = longueurBras1 * 0.0254;                    %  Converted from in 
longueurBras2 = longueurBras2 * 0.0254;                    %  Converted from in 
rayonDistanceAncrageEtPivot = rayonDistanceAncrageEtPivot * 0.001;
rayonDistanceMoteur = rayonDistanceMoteur * 0.001;         %  Converted from mm 
anglePlaqueTop_x = anglePlaqueTop_x * DEGtoRAD;            %  Converted from deg 
anglePlaqueTop_y = anglePlaqueTop_y * DEGtoRAD;            %  Converted from deg 
hauteurPlaqueTop = hauteurPlaqueTop * 0.001;               %  Converted from mm 

VAR(1) = distancePlaqueTop_x;
VAR(2) = distancePlaqueTop_y;
VAR(3) = anglePlaqueTop_z;
VAR(4) = angleMot1;
VAR(5) = angleMot2;
VAR(6) = angleMot3;
VAR(7) = angleBras1Middle;
VAR(8) = angleBras2Middle;
VAR(9) = angleBras3Middle;
SolutionToAlgebraicEquations = SolveSetOfNonlinearAlgebraicEquations( transpose(VAR), absError );
ErrorInConvergenceOfSolution = CalculateFunctionEvaluatedAtX( SolutionToAlgebraicEquations );
MaxErrorInConvergence = max( abs(ErrorInConvergenceOfSolution) );
Output = CalculateOutput( MaxErrorInConvergence );
OutputToScreenOrFile( Output, shouldPrintToScreen, shouldPrintToFile );
OutputToScreenOrFile( [], 0, 0 );   % Close output files.
Output = Output(11:13);               % Truncate Output matrix for proper return size.


%===========================================================================
function RHS = CalculateFunctionEvaluatedAtX( VAR )
%===========================================================================
% Update variables with new values
distancePlaqueTop_x = VAR(1);
distancePlaqueTop_y = VAR(2);
anglePlaqueTop_z = VAR(3);
angleMot1 = VAR(4);
angleMot2 = VAR(5);
angleMot3 = VAR(6);
angleBras1Middle = VAR(7);
angleBras2Middle = VAR(8);
angleBras3Middle = VAR(9);
RHS = zeros( 1, 9 );
RHS(1) = distancePlaqueTop_x - rayonDistanceAncrageEtPivot*cos(anglePlaqueTop_y)*sin(anglePlaqueTop_z);
RHS(2) = distancePlaqueTop_y + longueurBras2*cos(angleBras1Middle-angleMot1) + rayonDistanceAncrageEtPivot*(cos(anglePlaqueTop_x)*  ...
cos(anglePlaqueTop_z)-sin(anglePlaqueTop_x)*sin(anglePlaqueTop_y)*sin(anglePlaqueTop_z)) - rayonDistanceMoteur - longueurBras1*cos(angleMot1);
RHS(3) = hauteurPlaqueTop + rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*cos(anglePlaqueTop_z)+sin(anglePlaqueTop_y)*cos(  ...
anglePlaqueTop_x)*sin(anglePlaqueTop_z)) - hauteurAxeMoteur - longueurBras1*sin(angleMot1) - longueurBras2*sin(angleBras1Middle-  ...
angleMot1);
RHS(4) = distancePlaqueTop_x + 0.8660254037844386*longueurBras2*cos(angleBras2Middle-angleMot2) + 0.5*  ...
rayonDistanceAncrageEtPivot*cos(anglePlaqueTop_y)*sin(anglePlaqueTop_z) + 0.8660254037844386*rayonDistanceAncrageEtPivot*cos(  ...
anglePlaqueTop_y)*cos(anglePlaqueTop_z) - 0.8660254037844386*rayonDistanceMoteur - 0.8660254037844386*longueurBras1*cos(angleMot2);
RHS(5) = 0.5*rayonDistanceMoteur + distancePlaqueTop_y + 0.5*longueurBras1*cos(angleMot2) + 0.8660254037844386*  ...
rayonDistanceAncrageEtPivot*(cos(anglePlaqueTop_x)*sin(anglePlaqueTop_z)+sin(anglePlaqueTop_x)*sin(anglePlaqueTop_y)*cos(  ...
anglePlaqueTop_z)) - 0.5*longueurBras2*cos(angleBras2Middle-angleMot2) - 0.5*rayonDistanceAncrageEtPivot*(cos(anglePlaqueTop_x)*cos(  ...
anglePlaqueTop_z)-sin(anglePlaqueTop_x)*sin(anglePlaqueTop_y)*sin(anglePlaqueTop_z));
RHS(6) = hauteurPlaqueTop + 0.8660254037844386*rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*sin(anglePlaqueTop_z)-sin(  ...
anglePlaqueTop_y)*cos(anglePlaqueTop_x)*cos(anglePlaqueTop_z)) - hauteurAxeMoteur - longueurBras1*sin(angleMot2) - longueurBras2*  ...
sin(angleBras2Middle-angleMot2) - 0.5*rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*cos(anglePlaqueTop_z)+sin(  ...
anglePlaqueTop_y)*cos(anglePlaqueTop_x)*sin(anglePlaqueTop_z));
RHS(7) = 0.8660254037844386*rayonDistanceMoteur + distancePlaqueTop_x + 0.8660254037844386*longueurBras1*cos(angleMot3)  ...
+ 0.5*rayonDistanceAncrageEtPivot*cos(anglePlaqueTop_y)*sin(anglePlaqueTop_z) - 0.8660254037844386*longueurBras2*cos(  ...
angleBras3Middle-angleMot3) - 0.8660254037844386*rayonDistanceAncrageEtPivot*cos(anglePlaqueTop_y)*cos(anglePlaqueTop_z);
RHS(8) = 0.5*rayonDistanceMoteur + distancePlaqueTop_y + 0.5*longueurBras1*cos(angleMot3) - 0.5*longueurBras2*cos(  ...
angleBras3Middle-angleMot3) - 0.8660254037844386*rayonDistanceAncrageEtPivot*(cos(anglePlaqueTop_x)*sin(anglePlaqueTop_z)+sin(  ...
anglePlaqueTop_x)*sin(anglePlaqueTop_y)*cos(anglePlaqueTop_z)) - 0.5*rayonDistanceAncrageEtPivot*(cos(anglePlaqueTop_x)*cos(  ...
anglePlaqueTop_z)-sin(anglePlaqueTop_x)*sin(anglePlaqueTop_y)*sin(anglePlaqueTop_z));
RHS(9) = hauteurPlaqueTop - hauteurAxeMoteur - longueurBras1*sin(angleMot3) - longueurBras2*sin(angleBras3Middle-angleMot3)  ...
- 0.5*rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*cos(anglePlaqueTop_z)+sin(anglePlaqueTop_y)*cos(anglePlaqueTop_x)*sin(  ...
anglePlaqueTop_z)) - 0.8660254037844386*rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*sin(anglePlaqueTop_z)-sin(  ...
anglePlaqueTop_y)*cos(anglePlaqueTop_x)*cos(anglePlaqueTop_z));

end


%===========================================================================
function GradientAtX = CalculateGradientAtX( VAR )
%===========================================================================
RHS = CalculateFunctionEvaluatedAtX( VAR );
COEF = zeros( 9, 9 );
COEF(1,1) = -1;
COEF(1,3) = rayonDistanceAncrageEtPivot*cos(anglePlaqueTop_y)*cos(anglePlaqueTop_z);
COEF(2,2) = -1;
COEF(2,3) = rayonDistanceAncrageEtPivot*(cos(anglePlaqueTop_x)*sin(anglePlaqueTop_z)+sin(anglePlaqueTop_x)*sin(anglePlaqueTop_y)*  ...
cos(anglePlaqueTop_z));
COEF(2,4) = -longueurBras1*sin(angleMot1) - longueurBras2*sin(angleBras1Middle-angleMot1);
COEF(2,7) = longueurBras2*sin(angleBras1Middle-angleMot1);
COEF(3,3) = rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*sin(anglePlaqueTop_z)-sin(anglePlaqueTop_y)*cos(anglePlaqueTop_x)*  ...
cos(anglePlaqueTop_z));
COEF(3,4) = longueurBras1*cos(angleMot1) - longueurBras2*cos(angleBras1Middle-angleMot1);
COEF(3,7) = longueurBras2*cos(angleBras1Middle-angleMot1);
COEF(4,1) = -1;
COEF(4,3) = 0.5*rayonDistanceAncrageEtPivot*cos(anglePlaqueTop_y)*(1.732050807568877*sin(anglePlaqueTop_z)-cos(anglePlaqueTop_z));
COEF(4,5) = -0.8660254037844386*longueurBras1*sin(angleMot2) - 0.8660254037844386*longueurBras2*sin(angleBras2Middle-angleMot2);
COEF(4,8) = 0.8660254037844386*longueurBras2*sin(angleBras2Middle-angleMot2);
COEF(5,2) = -1;
COEF(5,3) = 0.5*rayonDistanceAncrageEtPivot*(1.732050807568877*sin(anglePlaqueTop_x)*sin(anglePlaqueTop_y)*sin(anglePlaqueTop_z)-  ...
1.732050807568877*cos(anglePlaqueTop_x)*cos(anglePlaqueTop_z)-cos(anglePlaqueTop_x)*sin(anglePlaqueTop_z)-sin(anglePlaqueTop_x)*sin(  ...
anglePlaqueTop_y)*cos(anglePlaqueTop_z));
COEF(5,5) = 0.5*longueurBras1*sin(angleMot2) + 0.5*longueurBras2*sin(angleBras2Middle-angleMot2);
COEF(5,8) = -0.5*longueurBras2*sin(angleBras2Middle-angleMot2);
COEF(6,3) = -0.5*rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*sin(anglePlaqueTop_z)+1.732050807568877*sin(anglePlaqueTop_x)*  ...
cos(anglePlaqueTop_z)+1.732050807568877*sin(anglePlaqueTop_y)*cos(anglePlaqueTop_x)*sin(anglePlaqueTop_z)-sin(anglePlaqueTop_y)*cos(  ...
anglePlaqueTop_x)*cos(anglePlaqueTop_z));
COEF(6,5) = longueurBras1*cos(angleMot2) - longueurBras2*cos(angleBras2Middle-angleMot2);
COEF(6,8) = longueurBras2*cos(angleBras2Middle-angleMot2);
COEF(7,1) = -1;
COEF(7,3) = -0.5*rayonDistanceAncrageEtPivot*cos(anglePlaqueTop_y)*(cos(anglePlaqueTop_z)+1.732050807568877*sin(anglePlaqueTop_z));
COEF(7,6) = 0.8660254037844386*longueurBras1*sin(angleMot3) + 0.8660254037844386*longueurBras2*sin(angleBras3Middle-angleMot3);
COEF(7,9) = -0.8660254037844386*longueurBras2*sin(angleBras3Middle-angleMot3);
COEF(8,2) = -1;
COEF(8,3) = 0.5*rayonDistanceAncrageEtPivot*(1.732050807568877*cos(anglePlaqueTop_x)*cos(anglePlaqueTop_z)-cos(anglePlaqueTop_x)*  ...
sin(anglePlaqueTop_z)-1.732050807568877*sin(anglePlaqueTop_x)*sin(anglePlaqueTop_y)*sin(anglePlaqueTop_z)-sin(anglePlaqueTop_x)*sin(  ...
anglePlaqueTop_y)*cos(anglePlaqueTop_z));
COEF(8,6) = 0.5*longueurBras1*sin(angleMot3) + 0.5*longueurBras2*sin(angleBras3Middle-angleMot3);
COEF(8,9) = -0.5*longueurBras2*sin(angleBras3Middle-angleMot3);
COEF(9,3) = -0.5*rayonDistanceAncrageEtPivot*(sin(anglePlaqueTop_x)*sin(anglePlaqueTop_z)-1.732050807568877*sin(anglePlaqueTop_x)*  ...
cos(anglePlaqueTop_z)-1.732050807568877*sin(anglePlaqueTop_y)*cos(anglePlaqueTop_x)*sin(anglePlaqueTop_z)-sin(anglePlaqueTop_y)*cos(  ...
anglePlaqueTop_x)*cos(anglePlaqueTop_z));
COEF(9,6) = longueurBras1*cos(angleMot3) - longueurBras2*cos(angleBras3Middle-angleMot3);
COEF(9,9) = longueurBras2*cos(angleBras3Middle-angleMot3);

GradientAtX = pinv(COEF) * transpose(RHS);
end



%===========================================================================
function [Output] = CalculateOutput( MaxErrorInConvergence )
%===========================================================================
Output = zeros( 1, 13 );
Output(1) = MaxErrorInConvergence;
Output(2) = distancePlaqueTop_x;
Output(3) = distancePlaqueTop_y;
Output(4) = anglePlaqueTop_z;
Output(5) = angleMot1;
Output(6) = angleMot2;
Output(7) = angleMot3;
Output(8) = angleBras1Middle;
Output(9) = angleBras2Middle;
Output(10) = angleBras3Middle;

Output(11) = angleMot1*RADtoDEG;                      % Converted to deg
Output(12) = angleMot2*RADtoDEG;                      % Converted to deg
Output(13) = angleMot3*RADtoDEG;                      % Converted to deg
end


%===========================================================================
function OutputToScreenOrFile( Output, shouldPrintToScreen, shouldPrintToFile )
%===========================================================================
persistent FileIdentifier hasHeaderInformationBeenWritten;

if( isempty(Output) ),
   if( ~isempty(FileIdentifier) ),
      fclose( FileIdentifier(1) );
      clear FileIdentifier;
      fprintf( 1, '\n Output is in the file anglePlaqueToAngleMoteur.1\n' );
   end
   if( shouldPrintToScreen ),
      fprintf( 1, '\n Output returned to the calling function:\n' );
      fprintf( 1, ' ResidualSum (UNITS)    distancePlaqueTop_x (UNITS)    distancePlaqueTop_y (UNITS)    anglePlaqueTop_z (UNITS)    angleMot1 (UNITS)    angleMot2 (UNITS)    angleMot3 (UNITS)    angleBras1Middle (UNITS)    angleBras2Middle (UNITS)    angleBras3Middle (UNITS) ... \n\n' );
   end
   clear hasHeaderInformationBeenWritten;
   return;
end

if( isempty(hasHeaderInformationBeenWritten) ),
   if( shouldPrintToScreen ),
      fprintf( 1,                '%%  ResidualSum   distancePlaqueTop_x distancePlaqueTop_y anglePlaqueTop_z    angleMot1      angleMot2      angleMot3   angleBras1Middle angleBras2Middle angleBras3Middle\n' );
      fprintf( 1,                '%%    (UNITS)           (UNITS)             (UNITS)           (UNITS)         (UNITS)        (UNITS)        (UNITS)         (UNITS)          (UNITS)          (UNITS)\n\n' );
   end
   if( shouldPrintToFile && isempty(FileIdentifier) ),
      FileIdentifier(1) = fopen('anglePlaqueToAngleMoteur.1', 'wt');   if( FileIdentifier(1) == -1 ), error('Error: unable to open file anglePlaqueToAngleMoteur.1'); end
      fprintf(FileIdentifier(1), '%% FILE: anglePlaqueToAngleMoteur.1\n%%\n' );
      fprintf(FileIdentifier(1), '%%  ResidualSum   distancePlaqueTop_x distancePlaqueTop_y anglePlaqueTop_z    angleMot1      angleMot2      angleMot3   angleBras1Middle angleBras2Middle angleBras3Middle\n' );
      fprintf(FileIdentifier(1), '%%    (UNITS)           (UNITS)             (UNITS)           (UNITS)         (UNITS)        (UNITS)        (UNITS)         (UNITS)          (UNITS)          (UNITS)\n\n' );
   end
   hasHeaderInformationBeenWritten = 1;
end

if( shouldPrintToScreen ), WriteNumericalData( 1,                 Output(1:10) );  end
if( shouldPrintToFile ),   WriteNumericalData( FileIdentifier(1), Output(1:10) );  end
end


%===========================================================================
function WriteNumericalData( fileIdentifier, Output )
%===========================================================================
numberOfOutputQuantities = length( Output );
if( numberOfOutputQuantities > 0 ),
   for( i = 1 : numberOfOutputQuantities ),
      fprintf( fileIdentifier, ' %- 14.6E', Output(i) );
   end
   fprintf( fileIdentifier, '\n' );
end
end



%===========================================================================
function SolutionToAlgebraicEquations = SolveSetOfNonlinearAlgebraicEquations( X, AbsoluteError )
%===========================================================================
alphaBest = 0.1;
for( numberOfGradientCalculations = 0:  1:  100),
   magErrorInSetOfFunctions = CalculateErrorInSetOfFunctions( X );
   if( magErrorInSetOfFunctions < AbsoluteError ), break; end
   dX = CalculateGradientAtX( X );
   if( max(abs(dX)) == 0.0 ), warning('Nonlinear solver failed (dX == 0)'); break;  end
   alphaBest = CalculateBestValueOfAlpha( X, alphaBest, dX, magErrorInSetOfFunctions );
   if( alphaBest == 0.0 ), warning('Nonlinear solver failed (alphaBest == 0)'); break;  end
   X = X + alphaBest*dX;
end
if( numberOfGradientCalculations >= 100 ), warning('Nonlinear solver failed (too many gradient calculations)'); end
SolutionToAlgebraicEquations = X;
end



%===========================================================================
function alphaBest = CalculateBestValueOfAlpha( X, alphaLastIteration, dX, magErrorInSetOfFunctionsAtAlpha0 )
%===========================================================================
if( alphaLastIteration > 0.5 ), alphaLastIteration = 0.5;  end
alpha = [ 0;  0.8*alphaLastIteration;  1.2*alphaLastIteration;  2.0*alphaLastIteration ];
error(4) = CalculateErrorInSetOfFunctions( X + alpha(4) * dX );
error(3) = CalculateErrorInSetOfFunctions( X + alpha(3) * dX );
error(2) = CalculateErrorInSetOfFunctions( X + alpha(2) * dX );
error(1) = magErrorInSetOfFunctionsAtAlpha0;
alphaBest = 0.0;
for( numberOfTries = 0:  1:  20),
   if( error(1) < error(2)  ||  error(2) < error(3) ),
      alpha(4) = alpha(3);  alpha(3) = alpha(2);  alpha(2) = 0.5*(alpha(1)+alpha(2));
      error(4) = error(3);  error(3) = error(2);  error(2) = CalculateErrorInSetOfFunctions( X+alpha(2)*dX );
   elseif( error(3) < error(4) ),
      space12 = alpha(2) - alpha(1);
      space23 = alpha(3) - alpha(2);
      space34 = alpha(4) - alpha(3);
      if( space12 >= 0.99*space23  &&  space12 >= 0.99*space34 ),
         alpha(4) = alpha(3);  alpha(3) = alpha(2);  alpha(2) = 0.5*(alpha(1)+alpha(2));
         error(4) = error(3);  error(3) = error(2);  error(2) = CalculateErrorInSetOfFunctions( X+alpha(2)*dX );
      elseif( space34 >= 0.99*space23 ),
         alpha(4) = 0.5*(alpha(3)+alpha(4));
         error(4) = CalculateErrorInSetOfFunctions( X+alpha(4)*dX );
      else
         alpha(4) = alpha(3);  alpha(3) = 0.5*(alpha(2)+alpha(3));
         error(4) = error(3);  error(3) = CalculateErrorInSetOfFunctions( X+alpha(3)*dX );
      end
   elseif( error(4) < error(1) ),
      alphaBest = alpha(4);   break;
   end
end
end



%===========================================================================
function ErrorInSetOfFunctions = CalculateErrorInSetOfFunctions( X )
%===========================================================================
ErrorInSetOfFunctions = norm( CalculateFunctionEvaluatedAtX(X) );
end


%=============================
end    % End of function anglePlaqueToAngleMoteur
%=============================
