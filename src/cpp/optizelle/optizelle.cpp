/*
Copyright 2013-2014 OptimoJoe.

For the full copyright notice, see LICENSE.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Author: Joseph Young (joe@optimojoe.com)
*/

#include "optizelle/optizelle.h"

namespace Optizelle{

    // Prints a message
    void Messaging::print(std::string const & msg) const {
        std::cout << msg << std::endl;
    }

    // Prints an error
    void Messaging::error(std::string const & msg) const {
        std::cerr << msg << std::endl;
        exit(EXIT_FAILURE);
    }

    // Allow a derived class to deallocate memory
    Messaging::~Messaging() {}

    // Which algorithm class do we use
    namespace AlgorithmClass{
        // Converts the algorithm class to a string
        std::string to_string(t const & algorithm_class){
            switch(algorithm_class){
            case TrustRegion:
                return "TrustRegion";
            case LineSearch:
                return "LineSearch";
            case UserDefined:
                return "UserDefined";
            default:
                throw;
            }
        }
        
        // Converts a string to an algorithm class 
        t from_string(std::string const & algorithm_class){
            if(algorithm_class=="TrustRegion")
                return TrustRegion;
            else if(algorithm_class=="LineSearch")
                return LineSearch;
            else if(algorithm_class=="UserDefined")
                return UserDefined;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="TrustRegion" ||
                name=="LineSearch" ||
                name=="UserDefined"
            )
                return true;
            else
                return false;
        }
    }

    // Reasons why we stop the algorithm
    namespace OptimizationStop{
        // Converts the stopping condition to a string 
        std::string to_string(t const & opt_stop) {
            switch(opt_stop){
            case NotConverged:
                return "NotConverged";
            case GradientSmall:
                return "GradientSmall";
            case StepSmall:
                return "StepSmall";
            case MaxItersExceeded:
                return "MaxItersExceeded";
            case InteriorPointInstability:
                return "InteriorPointInstability";
            case GlobalizationFailure:
                return "GlobalizationFailure";
            case UserDefined:
                return "UserDefined";
            default:
                throw;
            }
        }

        // Converts a string to a stopping condition
        t from_string(std::string const & opt_stop) {
            if(opt_stop=="NotConverged")
                return NotConverged;
            else if(opt_stop=="GradientSmall")
                return GradientSmall;
            else if(opt_stop=="StepSmall")
                return StepSmall;
            else if(opt_stop=="MaxItersExceeded")
                return MaxItersExceeded;
            else if(opt_stop=="InteriorPointInstability")
                return InteriorPointInstability; 
            else if(opt_stop=="GlobalizationFailure")
                return GlobalizationFailure;
            else if(opt_stop=="UserDefined")
                return UserDefined;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="NotConverged" ||
                name=="GradientSmall" ||
                name=="StepSmall" ||
                name=="MaxItersExceeded" ||
                name=="InteriorPointInstability" ||
                name=="GlobalizationFailure" ||
                name=="UserDefined"
            )
                return true;
            else
                return false;
        }
    }

    // Various operators for both Hessian approximations and preconditioners
    namespace Operators{
        // Converts the operator type to a string 
        std::string to_string(t const & op) {
            switch(op){
            case Identity:
                return "Identity";
            case ScaledIdentity:
                return "ScaledIdentity";
            case BFGS:
                return "BFGS";
            case InvBFGS:
                return "InvBFGS";
            case SR1:
                return "SR1";
            case InvSR1:
                return "InvSR1";
            case UserDefined:
                return "UserDefined";
            default:
                throw;
            }
        }
        
        // Converts a string to a operator 
        t from_string(std::string const & op) {
            if(op=="Identity")
                return Identity; 
            else if(op=="ScaledIdentity")
                return ScaledIdentity; 
            else if(op=="BFGS")
                return BFGS; 
            else if(op=="InvBFGS")
                return InvBFGS; 
            else if(op=="SR1")
                return SR1; 
            else if(op=="InvSR1")
                return InvSR1; 
            else if(op=="UserDefined")
                return UserDefined; 
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="Identity" ||
                name=="ScaledIdentity" ||
                name=="BFGS" ||
                name=="InvBFGS" ||
                name=="SR1" ||
                name=="InvSR1" ||
                name=="UserDefined" 
            )
                return true;
            else
                return false;
        }
    }

    // Different kinds of search directions 
    namespace LineSearchDirection{

        // Converts the line-search direction to a string 
        std::string to_string(t const & dir){
            switch(dir){
            case SteepestDescent:
                return "SteepestDescent";
            case FletcherReeves:
                return "FletcherReeves";
            case PolakRibiere:
                return "PolakRibiere";
            case HestenesStiefel:
                return "HestenesStiefel";
            case BFGS:
                return "BFGS";
            case NewtonCG:
                return "NewtonCG";
            default:
                throw;
            }
        }
        
        // Converts a string to a line-search direction 
        t from_string(std::string const & dir) {
            if(dir=="SteepestDescent")
                return SteepestDescent; 
            else if(dir=="FletcherReeves")
                return FletcherReeves; 
            else if(dir=="PolakRibiere")
                return PolakRibiere; 
            else if(dir=="HestenesStiefel")
                return HestenesStiefel; 
            else if(dir=="BFGS")
                return BFGS; 
            else if(dir=="NewtonCG")
                return NewtonCG; 
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="SteepestDescent" ||
                name=="FletcherReeves" ||
                name=="PolakRibiere" ||
                name=="HestenesStiefel" ||
                name=="BFGS" ||
                name=="NewtonCG"
            )
                return true;
            else
                return false;
        }
    } 

    // Different sorts of line searches
    namespace LineSearchKind{

        // Converts the line-search kind to a string 
        std::string to_string(t const & kind) {
            switch(kind){
            case GoldenSection:
                return "GoldenSection";
            case BackTracking:
                return "BackTracking";
            case TwoPointA:
                return "TwoPointA";
            case TwoPointB:
                return "TwoPointB";
            default:
                throw;
            }
        }
        
        // Converts a string to a line-search kind 
        t from_string(std::string const & kind) {
            if(kind=="GoldenSection")
                return GoldenSection; 
            else if(kind=="BackTracking")
                return BackTracking; 
            else if(kind=="TwoPointA")
                return TwoPointA; 
            else if(kind=="TwoPointB")
                return TwoPointB; 
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="GoldenSection" ||
                name=="BackTracking" ||
                name=="TwoPointA" ||
                name=="TwoPointB" 
            )
                return true;
            else
                return false;
        }

        // Determine whether or not the line-search checks the sufficient
        // decrease condition.
        bool is_sufficient_decrease(t const & kind) {
            switch(kind){
            case GoldenSection:
            case BackTracking:
                return true;
            case TwoPointA:
            case TwoPointB:
                return false;
            default:
                throw;
            }
        }
    }
        
    // Different points in the optimization algorithm
    namespace OptimizationLocation {

        // Converts the optimization location to a string 
        std::string to_string(t const & loc) {
            switch(loc){
            case BeginningOfOptimization:
                return "BeginningOfOptimization";
            case BeforeInitialFuncAndGrad:
                return "BeforeInitialFuncAndGrad";
            case AfterInitialFuncAndGrad:
                return "AfterInitialFuncAndGrad";
            case BeforeOptimizationLoop:
                return "BeforeOptimizationLoop";
            case BeginningOfOptimizationLoop:
                return "BeginningOfOptimizationLoop";
            case BeforeSaveOld:
                return "BeforeSaveOld";
            case BeforeStep:
                return "BeforeStep";
            case BeforeGetStep:
                return "BeforeGetStep";
            case GetStep:
                return "GetStep";
            case AfterStepBeforeGradient:
                return "AfterStepBeforeGradient";
            case AfterGradient:
                return "AfterGradient";
            case BeforeQuasi:
                return "BeforeQuasi";
            case AfterQuasi:
                return "AfterQuasi";
            case EndOfOptimizationIteration:
                return "EndOfOptimizationIteration";
            case BeforeLineSearch:
                return "BeforeLineSearch";
            case AfterRejectedTrustRegion:
                return "AfterRejectedTrustRegion";
            case AfterRejectedLineSearch:
                return "AfterRejectedLineSearch";
            case BeforeActualVersusPredicted:
                return "BeforeActualVersusPredicted";
            case EndOfOptimization:
                return "EndOfOptimization";
            default:
                throw;
            }
        }
        
        // Converts a string to a line-search kind 
        t from_string(std::string const & loc) {
            if(loc=="BeginningOfOptimization")
                return BeginningOfOptimization;
            else if(loc=="BeforeInitialFuncAndGrad")
                return BeforeInitialFuncAndGrad;
            else if(loc=="AfterInitialFuncAndGrad")
                return AfterInitialFuncAndGrad;
            else if(loc=="BeforeOptimizationLoop")
                return BeforeOptimizationLoop;
            else if(loc=="BeginningOfOptimizationLoop")
                return BeginningOfOptimizationLoop;
            else if(loc=="BeforeSaveOld")
                return BeforeSaveOld; 
            else if(loc=="BeforeStep")
                return BeforeStep; 
            else if(loc=="BeforeGetStep")
                return BeforeGetStep; 
            else if(loc=="GetStep")
                return GetStep; 
            else if(loc=="AfterStepBeforeGradient")
                return AfterStepBeforeGradient; 
            else if(loc=="AfterGradient")
                return AfterGradient;
            else if(loc=="BeforeQuasi")
                return BeforeQuasi;
            else if(loc=="AfterQuasi")
                return AfterQuasi;
            else if(loc=="EndOfOptimizationIteration")
                return EndOfOptimizationIteration; 
            else if(loc=="BeforeLineSearch")
                return BeforeLineSearch;
            else if(loc=="AfterRejectedTrustRegion")
                return AfterRejectedTrustRegion;
            else if(loc=="AfterRejectedLineSearch")
                return AfterRejectedLineSearch;
            else if(loc=="BeforeActualVersusPredicted")
                return BeforeActualVersusPredicted;
            else if(loc=="EndOfOptimization")
                return EndOfOptimization;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="BeginningOfOptimization" ||
                name=="BeforeInitialFuncAndGrad" ||
                name=="AfterInitialFuncAndGrad" ||
                name=="BeforeOptimizationLoop" ||
                name=="BeginningOfOptimizationLoop" ||
                name=="BeforeSaveOld" || 
                name=="BeforeStep" || 
                name=="BeforeGetStep" || 
                name=="GetStep" || 
                name=="AfterStepBeforeGradient" ||
                name=="AfterGradient" ||
                name=="BeforeQuasi" ||
                name=="AfterQuasi" ||
                name=="EndOfOptimizationIteration" ||
                name=="BeforeLineSearch" ||
                name=="AfterRejectedTrustRegion" ||
                name=="AfterRejectedLineSearch" ||
                name=="BeforeActualVersusPredicted" ||
                name=="EndOfOptimization"
            )
                return true;
            else
                return false;
        }
    }
    
    // Different problem classes
    namespace ProblemClass{
        
        // Converts the problem class to a string
        std::string to_string(t const & problem_class){
            switch(problem_class){
            case Unconstrained:
                return "Unconstrained";
            case EqualityConstrained:
                return "EqualityConstrained";
            case InequalityConstrained:
                return "InequalityConstrained";
            case Constrained:
                return "Constrained";
            default:
                    throw;
            }
        }

        // Converts a string to a problem class 
        t from_string(std::string const &problem_class){
            if(problem_class=="Unconstrained")
                return Unconstrained;
            else if(problem_class=="EqualityConstrained")
                return EqualityConstrained;
            else if(problem_class=="InequalityConstrained")
                return InequalityConstrained;
            else if(problem_class=="Constrained")
                return Constrained;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="Unconstrained" ||
                name=="EqualityConstrained" ||
                name=="InequalityConstrained" ||
                name=="Constrained" 
            )
                return true;
            else
                return false;
        }
    }
    
    // Different diagnostic tests on the optimization functions 
    namespace FunctionDiagnostics{

        // Converts the diagnostic checks to a string
        std::string to_string(t const & diag) {
            switch(diag){
            case NoDiagnostics: 
                return "NoDiagnostics";
            case FirstOrder: 
                return "FirstOrder";
            case SecondOrder: 
                return "SecondOrder";
            default:
                throw;
            }
        }
        
        // Converts a string to the diagnostic checks 
        t from_string(std::string const & diag) {
            if(diag=="NoDiagnostics")
                return NoDiagnostics; 
            else if(diag=="FirstOrder")
                return FirstOrder;
            else if(diag=="SecondOrder")
                return SecondOrder;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="NoDiagnostics" ||
                name=="FirstOrder" ||
                name=="SecondOrder" 
            )
                return true;
            else
                return false;
        }
    }
    
    // Different diagnostic tests on the optimization functions 
    namespace DiagnosticScheme {

        // Converts the diagnostic scheme to a string
        std::string to_string(t const & dscheme) {
            switch(dscheme){
            case Never: 
                return "Never";
            case DiagnosticsOnly: 
                return "DiagnosticsOnly";
            case EveryIteration: 
                return "EveryIteration";
            default:
                throw;
            }
        }
        
        // Converts a string to the diagnostic scheme 
        t from_string(std::string const & dscheme) {
            if(dscheme=="Never")
                return Never; 
            else if(dscheme=="DiagnosticsOnly")
                return DiagnosticsOnly;
            else if(dscheme=="EveryIteration")
                return EveryIteration;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="Never" ||
                name=="DiagnosticsOnly" ||
                name=="EveryIteration" 
            )
                return true;
            else
                return false;
        }
    }

    // Different diagnostics on the algebra 
    namespace VectorSpaceDiagnostics{

        // Converts the diagnostic checks to a string
        std::string to_string(t const & diag) {
            switch(diag){
            case NoDiagnostics: 
                return "NoDiagnostics";
            case Basic: 
                return "Basic";
            case EuclideanJordan: 
                return "EuclideanJordan";
            default:
                throw;
            }
        }
        
        // Converts a string to the diagnostic checks 
        t from_string(std::string const & diag) {
            if(diag=="NoDiagnostics")
                return NoDiagnostics; 
            else if(diag=="Basic")
                return Basic;
            else if(diag=="EuclideanJordan")
                return EuclideanJordan;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="NoDiagnostics" ||
                name=="Basic" ||
                name=="EuclideanJordan" 
            )
                return true;
            else
                return false;
        }
    }

    // Different kinds of stopping tolerances 
    namespace ToleranceKind{

        // Converts the kind of stopping tolerance to a string
        std::string to_string(t const & eps_rel) {
            switch(eps_rel){
            case Relative: 
                return "Relative";
            case Absolute: 
                return "Absolute";
            default:
                throw;
            }
        }
        
        // Converts a string to the kind of stopping tolerance
        t from_string(std::string const & eps_rel) {
            if(eps_rel=="Relative")
                return Relative; 
            else if(eps_rel=="Absolute")
                return Absolute;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="Relative" ||
                name=="Absolute"
            )
                return true;
            else
                return false;
        }
    }
    
    // Reasons why the quasinormal problem exited
    namespace QuasinormalStop{

        // Converts the quasinormal stopping condition to a string 
        std::string to_string(t const & qn_stop) {
            switch(qn_stop){
            case Newton: 
                return "Newton";
            case CauchyTrustRegion: 
                return "CauchyTrustRegion";
            case CauchySafeguard: 
                return "CauchySafeguard";
            case DoglegTrustRegion: 
                return "DoglegTrustRegion";
            case DoglegSafeguard: 
                return "DoglegSafeguard";
            case NewtonTrustRegion: 
                return "NewtonTrustRegion";
            case NewtonSafeguard: 
                return "NewtonSafeguard";
            case Skipped: 
                return "Skipped";
            case CauchySolved: 
                return "CauchySolved";
            default:
                throw;
            }
        }
        
        // Converts a string to a quasinormal stopping condition
        t from_string(std::string const & qn_stop) {
            if(qn_stop=="Newton")
                return Newton; 
            else if(qn_stop=="CauchyTrustRegion")
                return CauchyTrustRegion;
            else if(qn_stop=="CauchySafeguard")
                return CauchySafeguard;
            else if(qn_stop=="DoglegTrustRegion")
                return DoglegTrustRegion;
            else if(qn_stop=="DoglegSafeguard")
                return DoglegSafeguard;
            else if(qn_stop=="NewtonTrustRegion")
                return NewtonTrustRegion;
            else if(qn_stop=="NewtonSafeguard")
                return NewtonSafeguard;
            else if(qn_stop=="Skipped")
                return Skipped;
            else if(qn_stop=="CauchySolved")
                return CauchySolved;
            else
                throw;
        }

        // Checks whether or not a string is valid
        bool is_valid(std::string const & name) {
            if( name=="Newton" ||
                name=="CauchyTrustRegion" ||
                name=="CauchySafeguard" ||
                name=="DoglegTrustRegion" ||
                name=="DoglegSafeguard" ||
                name=="NewtonTrustRegion" ||
                name=="NewtonSafeguard" ||
                name=="Skipped" ||
                name=="CauchySolved"
            )
                return true;
            else
                return false;
        }
    }

    // Converts a variety of basic datatypes to strings
    std::ostream& Utility::formatReal(std::ostream & out) {
        return out<<std::setprecision(2) << std::scientific << std::setw(12)
            << std::left;
    }
    std::ostream& Utility::formatInt(std::ostream & out) {
        return out << std::setw(12) << std::left;
    }
    std::ostream& Utility::formatString(std::ostream & out) {
        return out << std::setw(12) << std::left;
    }
    
    // Converts anything to a string.
    std::string Utility::atos(double const & x){
        std::stringstream ss;
        ss << formatReal << x;
        return ss.str();
    }
    std::string Utility::atos(Natural const & x){
        std::stringstream ss;
        ss << formatInt << x;
        return ss.str();
    }
    std::string Utility::atos(std::string const & x){
        std::stringstream ss;
        ss << formatString << x;
        return ss.str();
    }
    std::string Utility::atos(TruncatedStop::t const & x){
        std::stringstream ss;
        // Converts the truncated CG stopping condition to a shorter string 
        switch(x){
        case TruncatedStop::NotConverged:
            return atos("NotConv");
        case TruncatedStop::NegativeCurvature:
            return atos("NegCurv");
        case TruncatedStop::RelativeErrorSmall:
            return atos("RelErrSml");
        case TruncatedStop::MaxItersExceeded:
            return atos("IterExcd");
        case TruncatedStop::TrustRegionViolated:
            return atos("TrstReg");
        case TruncatedStop::NanOperator:
            return atos("NanOp");
        case TruncatedStop::NanPreconditioner:
            return atos("NanPre");
        case TruncatedStop::NonProjectorPreconditioner:
            return atos("NonProjPre");
        case TruncatedStop::NonSymmetricPreconditioner:
            return atos("NonSymmPre");
        case TruncatedStop::NonSymmetricOperator:
            return atos("NonSymmOp");
        case TruncatedStop::LossOfOrthogonality:
            return atos("OrthogLost");
        case TruncatedStop::OffsetViolatesTrustRegion:
            return atos("OffsetTR");
        case TruncatedStop::OffsetViolatesSafeguard:
            return atos("OffsetSafe");
        case TruncatedStop::TooManyFailedSafeguard:
            return atos("Safeguard");
        case TruncatedStop::ObjectiveIncrease:
            return atos("ObjIncr");
        default:
            throw;
        }
    }
    std::string Utility::atos(QuasinormalStop::t const & x){
        std::stringstream ss;
        // Converts the quasinormal stopping condition to a shorter string 
        switch(x){
        case QuasinormalStop::Newton:
            return atos("Newton");
        case QuasinormalStop::CauchyTrustRegion:
            return atos("CauchyTR");
        case QuasinormalStop::CauchySafeguard:
            return atos("CauchySafe");
        case QuasinormalStop::DoglegTrustRegion:
            return atos("DoglegTR");
        case QuasinormalStop::DoglegSafeguard:
            return atos("DoglegSafe");
        case QuasinormalStop::NewtonTrustRegion:
            return atos("NewtonTR");
        case QuasinormalStop::NewtonSafeguard:
            return atos("NewtonSafe");
        case QuasinormalStop::Skipped:
            return atos("Skipped");
        case QuasinormalStop::CauchySolved:
            return atos("CauchySlv");
        default:
            throw;
        }
    }
}
