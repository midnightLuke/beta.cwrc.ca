// dont' forget config stuff in settings.local.php

'use strict';

var gulp = require('gulp');
var paths = require('compass-options').dirs();
var compass = require('gulp-compass');
var uglify = require('gulp-uglify');
var browserSync = require('browser-sync');
var rename = require('gulp-rename');
var plumber = require ('gulp-plumber');
var gutil = require('gulp-util');
var del = require('del');
var autoprefixer = require('gulp-autoprefixer');

// var sourceJs = 'src_js';
var sourceJs = 'js';
var moduleSASS = '../../../default/modules/custom';

// report errors but continue gulpin'
var onError = function (err) {
  gutil.beep();
  console.log(err);
  this.emit('end'); // super crit
};

//////////////////////////////////////
// Begin Gulp Tasks
//////////////////////////////////////

////// DEVELOPMENT
//////////////////

// Compress Task (compress javascript)
gulp.task('compress', function(){
  gulp.src('js/**/*.js')
    .pipe(plumber({
      errorHandler: onError
    }))
    .pipe(rename(function (path) {
      path.basename += ".min";
      path.extname = ".js"
    }))
    .pipe(uglify({
      preserveComments: "some"
    }))
    .pipe(gulp.dest(paths.js));
});

// Concatanate all files in a folder, rename, mimify and move to a dist folder
// gulp.task('scripts', function() {
  // return gulp.src(sourceJs + '/**/*.js')
  // return gulp.src([sourceJs +  '/**/*.js'])
    // Concatenate everything within the JavaScript folder.
    // .pipe(concat('scripts.js'))
    // .pipe(gulp.dest(paths.js))
    // .pipe(rename('scripts.min.js'))
    // Minify the JavaScript.
    // .pipe(uglify())
    // .pipe(gulp.dest(paths.js));
// });

// Compass Task (compile sass)
gulp.task('compass', function() {
  return gulp.src(paths.sass + '/**/*.scss')
  // return gulp.src([paths.sass + '/**/*.scss', moduleSASS + '/**/**/.*scss'])
  // return gulp.src([paths.sass + '/**/*.scss', '../../../default/modules/custom/**/.*scss'])
    .pipe(plumber({
      errorHandler: onError
    }))
    .pipe(compass({
      config_file: './config.rb',
      css: paths.css,
      sass: paths.sass,
      bundle_exec: true,
      time: true,
      sourcemap: true
    }))
    // .pipe(autoprefixer({
    //   browsers: ['last 3 versions']
    // }))
    .pipe(gulp.dest(paths.css));
    // .pipe(browserSync.reload({stream:true}));
});

// Watch Task (for new changes)
gulp.task('watch', function() {
  gulp.watch(paths.sass + '/**/*.scss', ['compass']);
  // gulp.watch(paths.js + '/*.js', ['compress']);
  gulp.watch('js/**/*.js', ['compress']);
  // gulp.watch('../../../default/modules/custom/**/.*scss', ['compass']);
});

// BrowserSync Task (refresh browser if files change)
gulp.task('browserSync', function() {
  browserSync.init([
    paths.css +  '/**/*.css',
    paths.js + '/**/*.js',
    paths.img + '/**/*',
    paths.fonts + '/**/*',
  ]);
});

// Server Tasks
// run compress and compass right away, and start watching for new changes
gulp.task('default', ['compress','compass','watch','browserSync']);

////// PRODUCTION
/////////////////

// Delete CSS and Map files in prep for final build
gulp.task('clean:css', function() {
  del([
    paths.css + '/**/*.map',
    paths.css + '/**/*.css'
  ]);
});

// Recompile SASS files in prep for final build
gulp.task('clean:sass', function() {
  return gulp.src(paths.sass + '/**/*.scss')
    .pipe(compass({
      config_file: './config.rb',
      css: paths.css,
      sass: paths.sass,
      bundle_exec: true,
      time: true,
      sourcemap: false
    }))
    .pipe(gulp.dest(paths.css));
});

// Final Build Task for production sites
gulp.task('build', ['clean:css','clean:sass']);
